#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/* =========================================================
   COMMON DATA STRUCTURES
   ========================================================= */

typedef enum { BUY, SELL } Side;

typedef struct {
    int id;
    Side side;
    int qty;
    int price;
    int expiry;
} Order;

const char* side_str(Side s) { return s == BUY ? "BUY" : "SELL"; }
const char* opp_side_str(Side s) { return s == BUY ? "SELL" : "BUY"; }

/* =========================================================
   BASELINE IMPLEMENTATION (Unsorted Dynamic Arrays)
   ========================================================= */

Order* baseline_buys = NULL;
int b_buy_count = 0;
int b_buy_cap = 0;

Order* baseline_sells = NULL;
int b_sell_count = 0;
int b_sell_cap = 0;

void reset_baseline() {
    b_buy_count = 0;
    b_sell_count = 0;
}

void add_to_baseline(Order o) {
    if (o.side == BUY) {
        if (b_buy_count >= b_buy_cap) {
            b_buy_cap = b_buy_cap == 0 ? 16 : b_buy_cap * 2;
            baseline_buys = realloc(baseline_buys, b_buy_cap * sizeof(Order));
        }
        baseline_buys[b_buy_count++] = o;
    } else {
        if (b_sell_count >= b_sell_cap) {
            b_sell_cap = b_sell_cap == 0 ? 16 : b_sell_cap * 2;
            baseline_sells = realloc(baseline_sells, b_sell_cap * sizeof(Order));
        }
        baseline_sells[b_sell_count++] = o;
    }
}

void process_baseline(Order o, bool debug) {
    if (debug) printf("[BASELINE] Processing %s Order #%d (Qty: %d, Price: %d)\n", side_str(o.side), o.id, o.qty, o.price);

    Order** opp_book = (o.side == BUY) ? &baseline_sells : &baseline_buys;
    int* opp_count = (o.side == BUY) ? &b_sell_count : &b_buy_count;

    if (debug) printf("Scanning unordered %s list linearly...\n", opp_side_str(o.side));

    while (o.qty > 0) {
        int best_idx = -1;
        int best_price = (o.side == BUY) ? 2000000000 : -1;

        for (int i = 0; i < *opp_count; i++) {
            Order* opp = &((*opp_book)[i]);
            bool valid = false;

            if (o.side == BUY) {
                if (opp->price <= o.price) valid = true;
                if (debug) printf("-> Checking SELL Order #%d @ Price %d [%s]\n", opp->id, opp->price, valid ? "Valid candidate" : "No match - Price too high");
                if (valid && opp->price < best_price) { best_price = opp->price; best_idx = i; }
            } else {
                if (opp->price >= o.price) valid = true;
                if (debug) printf("-> Checking BUY Order #%d @ Price %d [%s]\n", opp->id, opp->price, valid ? "Valid candidate" : "No match - Price too low");
                if (valid && opp->price > best_price) { best_price = opp->price; best_idx = i; }
            }
        }

        if (best_idx != -1) {
            Order* match = &((*opp_book)[best_idx]);
            if (debug) printf("Best match chosen: Order #%d @ Price %d\n", match->id, match->price);

            int trade_qty = (o.qty < match->qty) ? o.qty : match->qty;
            o.qty -= trade_qty;
            match->qty -= trade_qty;

            if (debug) printf("Matched %d units.\n", trade_qty);

            if (match->qty == 0) {
                if (debug) printf("Order #%d fully filled and removed.\n", match->id);
                for (int j = best_idx; j < *opp_count - 1; j++) {
                    (*opp_book)[j] = (*opp_book)[j + 1];
                }
                (*opp_count)--;
            }
        } else {
            break;
        }
    }

    if (o.qty > 0) {
        if (debug) printf("No further matches found.\nRemaining qty (%d) added to %s book.\n", o.qty, side_str(o.side));
        add_to_baseline(o);
    }
}

void print_baseline_book() {
    printf("=== BASELINE FINAL ORDER BOOK ===\n");
    printf("BUY Book:\n");
    for (int i = 0; i < b_buy_count; i++) {
        printf("ID:%d Qty:%d @ Prc:%d\n", baseline_buys[i].id, baseline_buys[i].qty, baseline_buys[i].price);
    }
    printf("SELL Book:\n");
    for (int i = 0; i < b_sell_count; i++) {
        printf("ID:%d Qty:%d @ Prc:%d\n", baseline_sells[i].id, baseline_sells[i].qty, baseline_sells[i].price);
    }
}

/* =========================================================
   OPTIMIZED IMPLEMENTATION (RBTree + DLL + MinHeap)
   ========================================================= */

#define RED 0
#define BLACK 1

typedef struct PriceLevel PriceLevel;

typedef struct OrderNode {
    Order order;
    struct OrderNode *prev, *next;
    PriceLevel *parent_level;
    bool is_active;
} OrderNode;

struct PriceLevel {
    int price;
    Side side;
    OrderNode *head, *tail;
    struct PriceLevel *left, *right, *parent;
    int color;
};

typedef struct {
    PriceLevel *root;
} RBTree;

typedef struct {
    OrderNode **data;
    int capacity;
    int size;
} MinHeap;

PriceLevel TNULL_NODE;
PriceLevel *TNULL = &TNULL_NODE;

RBTree opt_buy_tree;
RBTree opt_sell_tree;
MinHeap expiry_heap;

PriceLevel *best_bid_node = NULL;
PriceLevel *best_ask_node = NULL;

void rb_delete(RBTree *tree, PriceLevel *z);

void init_optimized() {
    TNULL->color = BLACK;
    TNULL->left = TNULL->right = TNULL->parent = TNULL;
    TNULL->head = TNULL->tail = NULL;
    opt_buy_tree.root = TNULL;
    opt_sell_tree.root = TNULL;
    best_bid_node = TNULL;
    best_ask_node = TNULL;
    expiry_heap.capacity = 1024;
    expiry_heap.size = 0;
    expiry_heap.data = malloc(expiry_heap.capacity * sizeof(OrderNode*));
}

void min_heap_insert(OrderNode *node) {
    if (expiry_heap.size >= expiry_heap.capacity) {
        expiry_heap.capacity *= 2;
        expiry_heap.data = realloc(expiry_heap.data, expiry_heap.capacity * sizeof(OrderNode*));
    }
    int i = expiry_heap.size++;
    while (i != 0 && expiry_heap.data[(i - 1) / 2]->order.expiry > node->order.expiry) {
        expiry_heap.data[i] = expiry_heap.data[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    expiry_heap.data[i] = node;
}

OrderNode* min_heap_extract() {
    if (expiry_heap.size == 0) return NULL;
    OrderNode *min_node = expiry_heap.data[0];
    OrderNode *last_node = expiry_heap.data[--expiry_heap.size];
    if (expiry_heap.size > 0) {
        expiry_heap.data[0] = last_node;
        int i = 0;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;
            if (left < expiry_heap.size && expiry_heap.data[left]->order.expiry < expiry_heap.data[smallest]->order.expiry)
                smallest = left;
            if (right < expiry_heap.size && expiry_heap.data[right]->order.expiry < expiry_heap.data[smallest]->order.expiry)
                smallest = right;
            if (smallest != i) {
                OrderNode *temp = expiry_heap.data[i];
                expiry_heap.data[i] = expiry_heap.data[smallest];
                expiry_heap.data[smallest] = temp;
                i = smallest;
            } else break;
        }
    }
    return min_node;
}

void process_expiry(int current_time) {
    while (expiry_heap.size > 0 && expiry_heap.data[0]->order.expiry <= current_time) {
        OrderNode *expired = min_heap_extract();

        if (expired->is_active) {
            expired->is_active = false;
            PriceLevel *lvl = expired->parent_level;

            // O(1) Removal from Doubly Linked List
            if (expired->prev) expired->prev->next = expired->next;
            else lvl->head = expired->next;

            if (expired->next) expired->next->prev = expired->prev;
            else lvl->tail = expired->prev;

            // Cleanup Tree if Level becomes empty
            if (lvl->head == NULL) {
                RBTree *tree = (lvl->side == BUY) ? &opt_buy_tree : &opt_sell_tree;
                rb_delete(tree, lvl);
            }
        }
        free(expired); // Final cleanup: Guaranteed exactly one free per node.
    }
}

PriceLevel* create_price_level(int price, Side side) {
    PriceLevel* node = malloc(sizeof(PriceLevel));
    node->price = price;
    node->side = side;
    node->head = node->tail = NULL;
    node->parent = node->left = node->right = TNULL;
    node->color = RED;
    return node;
}

void left_rotate(RBTree *tree, PriceLevel *x) {
    PriceLevel *y = x->right;
    x->right = y->left;
    if (y->left != TNULL) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == TNULL) tree->root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void right_rotate(RBTree *tree, PriceLevel *y) {
    PriceLevel *x = y->left;
    y->left = x->right;
    if (x->right != TNULL) x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == TNULL) tree->root = x;
    else if (y == y->parent->right) y->parent->right = x;
    else y->parent->left = x;
    x->right = y;
    y->parent = x;
}

void rb_insert_fixup(RBTree *tree, PriceLevel *k) {
    PriceLevel *u;
    while (k->parent->color == RED) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u->color == RED) {
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    right_rotate(tree, k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                left_rotate(tree, k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;
            if (u->color == RED) {
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    left_rotate(tree, k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                right_rotate(tree, k->parent->parent);
            }
        }
        if (k == tree->root) break;
    }
    tree->root->color = BLACK;
}

PriceLevel* rb_insert(RBTree *tree, int price, Side side) {
    PriceLevel *node = create_price_level(price, side);
    PriceLevel *y = TNULL;
    PriceLevel *x = tree->root;
    while (x != TNULL) {
        y = x;
        if (node->price == x->price) {
            free(node);
            return x;
        }
        if (node->price < x->price) x = x->left;
        else x = x->right;
    }
    node->parent = y;
    if (y == TNULL) tree->root = node;
    else if (node->price < y->price) y->left = node;
    else y->right = node;

    if (node->parent == TNULL) {
        node->color = BLACK;
        return node;
    }
    if (node->parent->parent == TNULL) return node;
    rb_insert_fixup(tree, node);
    return node;
}

PriceLevel* tree_minimum(PriceLevel *node) {
    while (node->left != TNULL) node = node->left;
    return node;
}

PriceLevel* tree_maximum(PriceLevel *node) {
    while (node->right != TNULL) node = node->right;
    return node;
}

PriceLevel* tree_successor(PriceLevel *x) {
    if (x->right != TNULL) return tree_minimum(x->right);
    PriceLevel *y = x->parent;
    while (y != TNULL && x == y->right) { x = y; y = y->parent; }
    return y;
}

PriceLevel* tree_predecessor(PriceLevel *x) {
    if (x->left != TNULL) return tree_maximum(x->left);
    PriceLevel *y = x->parent;
    while (y != TNULL && x == y->left) { x = y; y = y->parent; }
    return y;
}

void rb_transplant(RBTree *tree, PriceLevel *u, PriceLevel *v) {
    if (u->parent == TNULL) tree->root = v;
    else if (u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    v->parent = u->parent;
}

void rb_delete_fixup(RBTree *tree, PriceLevel *x) {
    PriceLevel *w;
    while (x != tree->root && x->color == BLACK) {
        if (x == x->parent->left) {
            w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                left_rotate(tree, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(tree, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                left_rotate(tree, x->parent);
                x = tree->root;
            }
        } else {
            w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                right_rotate(tree, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(tree, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                right_rotate(tree, x->parent);
                x = tree->root;
            }
        }
    }
    x->color = BLACK;
}

void rb_delete(RBTree *tree, PriceLevel *z) {
    // Safely update BBO pointers locally before modifying tree structure
    if (z == best_bid_node) best_bid_node = tree_predecessor(z);
    if (z == best_ask_node) best_ask_node = tree_successor(z);

    PriceLevel *x, *y = z;
    int y_original_color = y->color;
    if (z->left == TNULL) {
        x = z->right;
        rb_transplant(tree, z, z->right);
    } else if (z->right == TNULL) {
        x = z->left;
        rb_transplant(tree, z, z->left);
    } else {
        y = tree_minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) { x->parent = y; }
        else {
            rb_transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rb_transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (y_original_color == BLACK) rb_delete_fixup(tree, x);
    free(z);
}

void process_optimized(Order o, bool debug) {
    if (debug) printf("[OPTIMIZED] Processing %s Order #%d (Qty: %d, Price: %d)\n", side_str(o.side), o.id, o.qty, o.price);

    // Simulated Time = Order ID. Pre-process active expiries first.
    process_expiry(o.id);

    RBTree *opp_tree = (o.side == BUY) ? &opt_sell_tree : &opt_buy_tree;
    RBTree *own_tree = (o.side == BUY) ? &opt_buy_tree : &opt_sell_tree;

    if (debug) printf("O(log N) jump directly to %s %s price node...\n", o.side == BUY ? "minimum" : "maximum", opp_side_str(o.side));

    // O(1) jump utilizing BBO cache instead of O(log N) tree_minimum/maximum scan
    PriceLevel *node = (o.side == BUY) ? best_ask_node : best_bid_node;

    while (node != TNULL && o.qty > 0) {
        if (o.side == BUY && node->price > o.price) break;
        if (o.side == SELL && node->price < o.price) break;

        if (debug) printf("-> Checking tree node @ Price %d\n", node->price);

        // Strict FIFO matching exclusively at the Head Node
        while (node->head != NULL && o.qty > 0) {
            OrderNode *curr = node->head;
            int trade_qty = (o.qty < curr->order.qty) ? o.qty : curr->order.qty;
            o.qty -= trade_qty;
            curr->order.qty -= trade_qty;

            if (debug) printf("Matched %d units with Order #%d\n", trade_qty, curr->order.id);

            // Pop Head Node when exhausted
            if (curr->order.qty == 0) {
                curr->is_active = false; // Prevents heap double-free/dangling pointers
                node->head = curr->next;
                if (node->head) node->head->prev = NULL;
                else node->tail = NULL;
            }
        }

        PriceLevel *next_node = (o.side == BUY) ? tree_successor(node) : tree_predecessor(node);
        if (node->head == NULL) {
            rb_delete(opp_tree, node);
        }
        node = next_node;
    }

    if (o.qty > 0) {
        if (debug) printf("Remaining qty (%d) inserted into %s RBTree.\n", o.qty, side_str(o.side));
        PriceLevel *lvl = rb_insert(own_tree, o.price, o.side);

        // Cache Maintenance
        if (o.side == BUY) {
            if (best_bid_node == TNULL || o.price > best_bid_node->price) best_bid_node = lvl;
        } else {
            if (best_ask_node == TNULL || o.price < best_ask_node->price) best_ask_node = lvl;
        }

        OrderNode *new_node = malloc(sizeof(OrderNode));
        new_node->order = o;
        new_node->next = NULL;
        new_node->prev = lvl->tail;
        new_node->parent_level = lvl;
        new_node->is_active = true;

        if (lvl->tail) lvl->tail->next = new_node;
        else lvl->head = new_node;
        lvl->tail = new_node;

        min_heap_insert(new_node); // Add to expiry tracking map
    }
}

void print_tree_desc(PriceLevel *node) {
    if (node == TNULL) return;
    print_tree_desc(node->right);
    OrderNode *curr = node->head;
    while(curr) {
        printf("ID:%d Qty:%d @ Prc:%d\n", curr->order.id, curr->order.qty, node->price);
        curr = curr->next;
    }
    print_tree_desc(node->left);
}

void print_tree_asc(PriceLevel *node) {
    if (node == TNULL) return;
    print_tree_asc(node->left);
    OrderNode *curr = node->head;
    while(curr) {
        printf("ID:%d Qty:%d @ Prc:%d\n", curr->order.id, curr->order.qty, node->price);
        curr = curr->next;
    }
    print_tree_asc(node->right);
}

void print_optimized_book() {
    printf("=== OPTIMIZED FINAL ORDER BOOK ===\n");
    printf("BUY Book (Descending Print):\n");
    print_tree_desc(opt_buy_tree.root);
    printf("SELL Book (Ascending Print):\n");
    print_tree_asc(opt_sell_tree.root);
}

void free_tree_nodes_only(PriceLevel *node) {
    if (node == TNULL) return;
    free_tree_nodes_only(node->left);
    free_tree_nodes_only(node->right);
    free(node);
}

void reset_optimized() {
    free_tree_nodes_only(opt_buy_tree.root);
    free_tree_nodes_only(opt_sell_tree.root);
    opt_buy_tree.root = TNULL;
    opt_sell_tree.root = TNULL;
    best_bid_node = TNULL;
    best_ask_node = TNULL;

    // Ensure orders are cleanly freed via the Heap to avoid Double-Frees
    for (int i = 0; i < expiry_heap.size; i++) {
        free(expiry_heap.data[i]);
    }
    expiry_heap.size = 0;
}

/* =========================================================
   DEMO & BENCHMARKING FRAMEWORK
   ========================================================= */

Order generate_random_order(int id) {
    Order o;
    o.id = id;
    o.side = (rand() % 2 == 0) ? BUY : SELL;
    o.qty = (rand() % 100) + 1;
    o.price = 100 + (rand() % 20) - 10; // Controlled spread ensures rapid matching
    o.expiry = id + 1000;
    return o;
}

void run_demo() {
    Order demo_orders[] = {
        {1, SELL, 50, 100, 1000},
        {2, SELL, 40, 110, 1000},
        {3, SELL, 30,  90, 1000},
        {4, BUY,  60, 105, 1000},
        {5, BUY,  20,  85, 1000}
    };
    int n = 5;

    printf("========================================================\n");
    printf("DEMO MODE (DEBUG ON)\n");
    printf("========================================================\n");
    printf("--- GENERATED DATASET ---\n");
    for (int i = 0; i < n; i++) {
        printf("Order ID: %d | Type: %s | Qty: %d | Price: %d\n", demo_orders[i].id, side_str(demo_orders[i].side), demo_orders[i].qty, demo_orders[i].price);
    }

    reset_baseline();
    printf("================ BASELINE EXECUTION ================\n");
    for (int i = 0; i < n; i++) process_baseline(demo_orders[i], true);
    print_baseline_book();

    reset_optimized();
    printf("================ OPTIMIZED EXECUTION ===============\n");
    for (int i = 0; i < n; i++) process_optimized(demo_orders[i], true);
    print_optimized_book();

    printf("================ COMPARISON SUMMARY ================\n");
    printf("* BASELINE required O(N) linear scans to find the global optimum price among unsorted arrays.\n");
    printf("* OPTIMIZED used an RBTree to make an O(log N) jump directly to the mathematical minimum/maximum price.\n");
}

void run_benchmark() {
    printf("========================================================\n");
    printf("PERFORMANCE MODE (DEBUG OFF - BENCHMARKING)\n");
    printf("========================================================\n");
    printf("%-10s %-18s %-18s %s\n", "Orders", "Baseline Time (s)", "Optimized Time (s)", "Improvement");
    printf("---------------------------------------------------------------------\n");

    int sizes[] = {500, 1000, 2000, 50000, 100000, 200000, 500000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    srand(42);

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        Order *bench_orders = malloc(n * sizeof(Order));
        srand(42);
        for (int j = 0; j < n; j++) bench_orders[j] = generate_random_order(j + 1);

        // Baseline Benchmark
        reset_baseline();
        clock_t start = clock();
        for (int j = 0; j < n; j++) process_baseline(bench_orders[j], false);
        clock_t end = clock();
        double base_time = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Optimized Benchmark
        reset_optimized();
        start = clock();
        for (int j = 0; j < n; j++) process_optimized(bench_orders[j], false);
        end = clock();
        double opt_time = ((double)(end - start)) / CLOCKS_PER_SEC;

        double improvement = (opt_time > 0) ? (base_time / opt_time) : 0;
        printf("%-10d %-18.6f %-18.6f %.2fx\n", n, base_time, opt_time, improvement);

        free(bench_orders);
    }
}

int main() {
    init_optimized();
    run_demo();
    run_benchmark();
    return 0;
}
