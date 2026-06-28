#include "order_book.h"

typedef struct {
    OrderNode **orders;
    int capacity;
    int size;
} MinHeap;

static RBNode *buy_tree = NULL;
static RBNode *sell_tree = NULL;
static MinHeap expiry_heap;

RBNode* rb_create_node(double price) {
    RBNode *node = (RBNode *)malloc(sizeof(RBNode));
    node->price = price;
    node->head = NULL;
    node->tail = NULL;
    node->order_count = 0;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->color = 1; // RED
    return node;
}

void rb_add_order_to_node(RBNode *node, Order *order) {
    OrderNode *new_order = (OrderNode *)malloc(sizeof(OrderNode));
    new_order->order = *order;
    new_order->next = NULL;
    new_order->prev = NULL;
    
    if (node->head == NULL) {
        node->head = new_order;
        node->tail = new_order;
    } else {
        node->tail->next = new_order;
        new_order->prev = node->tail;
        node->tail = new_order;
    }
    node->order_count++;
}

void rb_remove_order_from_node(RBNode *node, OrderNode *order) {
    if (order->prev) {
        order->prev->next = order->next;
    } else {
        node->head = order->next;
    }
    
    if (order->next) {
        order->next->prev = order->prev;
    } else {
        node->tail = order->prev;
    }
    
    node->order_count--;
    free(order);
}

RBNode* rb_search(RBNode *root, double price) {
    if (root == NULL) return NULL;
    if (root->price == price) return root;
    if (price < root->price) return rb_search(root->left, price);
    return rb_search(root->right, price);
}

RBNode* rb_find_min(RBNode *root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

RBNode* rb_find_max(RBNode *root) {
    if (root == NULL) return NULL;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

RBNode* rb_find_next_larger(RBNode *root, RBNode *current) {
    if (current->right != NULL) {
        return rb_find_min(current->right);
    }
    
    RBNode *parent = current->parent;
    RBNode *child = current;
    
    while (parent != NULL && child == parent->right) {
        child = parent;
        parent = parent->parent;
    }
    
    return parent;
}

RBNode* rb_find_next_smaller(RBNode *root, RBNode *current) {
    if (current->left != NULL) {
        return rb_find_max(current->left);
    }
    
    RBNode *parent = current->parent;
    RBNode *child = current;
    
    while (parent != NULL && child == parent->left) {
        child = parent;
        parent = parent->parent;
    }
    
    return parent;
}

void rb_rotate_left(RBNode **root, RBNode *node) {
    RBNode *right_child = node->right;
    node->right = right_child->left;
    
    if (right_child->left) {
        right_child->left->parent = node;
    }
    
    right_child->parent = node->parent;
    
    if (!node->parent) {
        *root = right_child;
    } else if (node == node->parent->left) {
        node->parent->left = right_child;
    } else {
        node->parent->right = right_child;
    }
    
    right_child->left = node;
    node->parent = right_child;
}

void rb_rotate_right(RBNode **root, RBNode *node) {
    RBNode *left_child = node->left;
    node->left = left_child->right;
    
    if (left_child->right) {
        left_child->right->parent = node;
    }
    
    left_child->parent = node->parent;
    
    if (!node->parent) {
        *root = left_child;
    } else if (node == node->parent->right) {
        node->parent->right = left_child;
    } else {
        node->parent->left = left_child;
    }
    
    left_child->right = node;
    node->parent = left_child;
}

RBNode* rb_insert(RBNode **root, double price, Order *order) {
    if (*root == NULL) {
        *root = rb_create_node(price);
        rb_add_order_to_node(*root, order);
        (*root)->color = 0; // ROOT is BLACK
        return *root;
    }
    
    RBNode *current = *root;
    
    while (1) {
        if (price == current->price) {
            rb_add_order_to_node(current, order);
            return current;
        } else if (price < current->price) {
            if (current->left == NULL) {
                current->left = rb_create_node(price);
                current->left->parent = current;
                rb_add_order_to_node(current->left, order);
                return current->left;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = rb_create_node(price);
                current->right->parent = current;
                rb_add_order_to_node(current->right, order);
                return current->right;
            }
            current = current->right;
        }
    }
}

void optimized_init() {
    buy_tree = NULL;
    sell_tree = NULL;
    expiry_heap.capacity = 10000;
    expiry_heap.size = 0;
    expiry_heap.orders = (OrderNode **)malloc(sizeof(OrderNode *) * expiry_heap.capacity);
}

void optimized_cleanup() {
    free(expiry_heap.orders);
}

void optimized_add_order(Order *order) {
    if (order->type == BUY) {
        rb_insert(&buy_tree, order->price, order);
    } else {
        rb_insert(&sell_tree, order->price, order);
    }
}

void optimized_process_order(Order *order, int debug) {
    int remaining_qty = order->quantity;
    
    if (debug) {
        printf("\n   [OPTIMIZED] Processing %s Order #%d (Qty: %d, Price: %.0f)\n",
               order->type == BUY ? "BUY" : "SELL",
               order->id, order->quantity, order->price);
    }
    
    if (order->type == BUY) {
        // BUY order: match with SELL orders
        if (debug) {
            printf("\n     O(log N) jump directly to minimum SELL price node...\n");
        }
        
        RBNode *current = rb_find_min(sell_tree);
        
        while (remaining_qty > 0 && current != NULL) {
            if (current->price <= order->price) {
                if (debug) {
                    printf("\n       -> Checking tree node @ Price %.0f\n", current->price);
                }
                
                // Match with head of the queue
                while (remaining_qty > 0 && current->head != NULL) {
                    OrderNode *sell_order = current->head;
                    
                    int matched_qty = (remaining_qty < sell_order->order.quantity) 
                                     ? remaining_qty 
                                     : sell_order->order.quantity;
                    
                    if (debug) {
                        printf("\n         Matched %d units with Order #%d\n",
                               matched_qty, sell_order->order.id);
                    }
                    
                    remaining_qty -= matched_qty;
                    sell_order->order.quantity -= matched_qty;
                    
                    if (sell_order->order.quantity == 0) {
                        rb_remove_order_from_node(current, sell_order);
                    }
                }
                
                // Move to next price level
                current = rb_find_next_larger(sell_tree, current);
            } else {
                break;
            }
        }
    } else {
        // SELL order: match with BUY orders
        if (debug) {
            printf("\n     O(log N) jump directly to maximum BUY price node...\n");
        }
        
        RBNode *current = rb_find_max(buy_tree);
        
        while (remaining_qty > 0 && current != NULL) {
            if (current->price >= order->price) {
                if (debug) {
                    printf("\n       -> Checking tree node @ Price %.0f\n", current->price);
                }
                
                // Match with head of the queue
                while (remaining_qty > 0 && current->head != NULL) {
                    OrderNode *buy_order = current->head;
                    
                    int matched_qty = (remaining_qty < buy_order->order.quantity) 
                                     ? remaining_qty 
                                     : buy_order->order.quantity;
                    
                    if (debug) {
                        printf("\n         Matched %d units with Order #%d\n",
                               matched_qty, buy_order->order.id);
                    }
                    
                    remaining_qty -= matched_qty;
                    buy_order->order.quantity -= matched_qty;
                    
                    if (buy_order->order.quantity == 0) {
                        rb_remove_order_from_node(current, buy_order);
                    }
                }
                
                // Move to next price level
                current = rb_find_next_smaller(buy_tree, current);
            } else {
                break;
            }
        }
    }
    
    // Add remaining quantity to book
    if (remaining_qty > 0) {
        Order remaining_order = *order;
        remaining_order.quantity = remaining_qty;
        optimized_add_order(&remaining_order);
    }
}

void optimized_print_book() {
    printf("\n   === OPTIMIZED FINAL ORDER BOOK ===\n\n");
    
    printf("   BUY Book (Descending Print):\n");
    RBNode *buy_current = rb_find_max(buy_tree);
    if (buy_current == NULL) {
        printf("\n     (empty)\n");
    } else {
        while (buy_current != NULL) {
            OrderNode *order = buy_current->head;
            while (order != NULL) {
                printf("\n     ID:%d Qty:%d @ Prc:%.0f\n",
                       order->order.id,
                       order->order.quantity,
                       order->order.price);
                order = order->next;
            }
            buy_current = rb_find_next_smaller(buy_tree, buy_current);
        }
    }
    
    printf("\n   SELL Book (Ascending Print):\n");
    RBNode *sell_current = rb_find_min(sell_tree);
    if (sell_current == NULL) {
        printf("\n     (empty)\n");
    } else {
        while (sell_current != NULL) {
            OrderNode *order = sell_current->head;
            while (order != NULL) {
                printf("\n     ID:%d Qty:%d @ Prc:%.0f\n",
                       order->order.id,
                       order->order.quantity,
                       order->order.price);
                order = order->next;
            }
            sell_current = rb_find_next_larger(sell_tree, sell_current);
        }
    }
    printf("\n");
}

BookEntry* optimized_get_entries(int *buy_count, int *sell_count) {
    BookEntry *result = (BookEntry *)malloc(sizeof(BookEntry) * MAX_ORDERS);
    int total = 0;
    
    RBNode *current = rb_find_max(buy_tree);
    *buy_count = 0;
    while (current != NULL) {
        OrderNode *order = current->head;
        while (order != NULL) {
            result[total].id = order->order.id;
            result[total].quantity = order->order.quantity;
            result[total].price = order->order.price;
            total++;
            (*buy_count)++;
            order = order->next;
        }
        current = rb_find_next_smaller(buy_tree, current);
    }
    
    *sell_count = 0;
    current = rb_find_min(sell_tree);
    while (current != NULL) {
        OrderNode *order = current->head;
        while (order != NULL) {
            result[total].id = order->order.id;
            result[total].quantity = order->order.quantity;
            result[total].price = order->order.price;
            total++;
            (*sell_count)++;
            order = order->next;
        }
        current = rb_find_next_larger(sell_tree, current);
    }
    
    return result;
}