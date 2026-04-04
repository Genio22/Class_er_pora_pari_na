#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <random>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// ==========================================
// SECTION 1: CORE REQUIREMENTS
// ==========================================
enum OrderType { BUY, SELL };

struct Order {
    int id;
    OrderType type;
    double price;
    int quantity;
    long long timestamp;
    long long expiry_time; 

    // For baseline matching comparison
    bool operator==(const Order& other) const { return id == other.id; }
};

// ==========================================
// SECTION 3.2: FIBONACCI HEAP (MANUAL)
// ==========================================
struct FibNode {
    long long key; // Expiry time
    Order* order;
    int degree;
    FibNode* parent;
    FibNode* child;
    FibNode* left;
    FibNode* right;
    bool mark;

    FibNode(long long k, Order* o) : key(k), order(o), degree(0), parent(nullptr), child(nullptr), mark(false) {
        left = right = this; // Circular list
    }
};

class FibonacciHeap {
private:
    FibNode* minNode;
    int numNodes;

    void link(FibNode* y, FibNode* x) {
        y->left->right = y->right;
        y->right->left = y->left;
        y->parent = x;
        if (x->child == nullptr) {
            x->child = y;
            y->right = y;
            y->left = y;
        } else {
            y->left = x->child;
            y->right = x->child->right;
            x->child->right->left = y;
            x->child->right = y;
        }
        x->degree++;
        y->mark = false;
    }

    void consolidate() {
        if (!minNode) return;
        int maxDegree = static_cast<int>(log2(numNodes)) + 2;
        vector<FibNode*> A(maxDegree, nullptr);

        vector<FibNode*> rootNodes;
        FibNode* x = minNode;
        if (x) {
            do {
                rootNodes.push_back(x);
                x = x->right;
            } while (x != minNode);
        }

        for (FibNode* w : rootNodes) {
            FibNode* x = w;
            int d = x->degree;
            while (A[d] != nullptr) {
                FibNode* y = A[d];
                if (x->key > y->key) swap(x, y);
                link(y, x);
                A[d] = nullptr;
                d++;
            }
            A[d] = x;
        }

        minNode = nullptr;
        for (int i = 0; i < maxDegree; i++) {
            if (A[i] != nullptr) {
                if (minNode == nullptr) {
                    minNode = A[i];
                    minNode->left = minNode->right = minNode;
                } else {
                    A[i]->left = minNode;
                    A[i]->right = minNode->right;
                    minNode->right->left = A[i];
                    minNode->right = A[i];
                    if (A[i]->key < minNode->key) minNode = A[i];
                }
            }
        }
    }

public:
    FibonacciHeap() : minNode(nullptr), numNodes(0) {}

    void insert(long long key, Order* order) {
        FibNode* node = new FibNode(key, order);
        if (minNode == nullptr) {
            minNode = node;
        } else {
            node->left = minNode;
            node->right = minNode->right;
            minNode->right->left = node;
            minNode->right = node;
            if (node->key < minNode->key) minNode = node;
        }
        numNodes++;
    }

    FibNode* extractMin() {
        FibNode* z = minNode;
        if (z != nullptr) {
            if (z->child != nullptr) {
                FibNode* child = z->child;
                do {
                    FibNode* next = child->right;
                    child->left = minNode;
                    child->right = minNode->right;
                    minNode->right->left = child;
                    minNode->right = child;
                    child->parent = nullptr;
                    child = next;
                } while (child != z->child);
            }
            z->left->right = z->right;
            z->right->left = z->left;
            if (z == z->right) {
                minNode = nullptr;
            } else {
                minNode = z->right;
                consolidate();
            }
            numNodes--;
        }
        return z;
    }
    
    bool isEmpty() const { return minNode == nullptr; }
};

// ==========================================
// SECTION 3.1: RED-BLACK TREE (MANUAL)
// ==========================================
enum Color { RED, BLACK };

struct RBNode {
    double price;
    list<Order> orders;
    Color color;
    RBNode *left, *right, *parent;

    RBNode(double p) : price(p), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree {
private:
    RBNode* root;
    RBNode* TNULL;
    bool isBuyTree; // Defines sorting direction logic

    void leftRotate(RBNode* x) {
        RBNode* y = x->right;
        x->right = y->left;
        if (y->left != TNULL) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rightRotate(RBNode* x) {
        RBNode* y = x->left;
        x->left = y->right;
        if (y->right != TNULL) y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    void insertFix(RBNode* k) {
        RBNode* u;
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
                        rightRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
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
                        leftRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) break;
        }
        root->color = BLACK;
    }

public:
    RBTree(bool buy) : isBuyTree(buy) {
        TNULL = new RBNode(0);
        TNULL->color = BLACK;
        root = TNULL;
    }

    RBNode* insertAndGetNode(double key, const Order& order) {
        RBNode* node = new RBNode(key);
        node->parent = nullptr;
        node->orders.push_back(order);
        node->left = TNULL;
        node->right = TNULL;
        node->color = RED;

        RBNode* y = nullptr;
        RBNode* x = root;

        while (x != TNULL) {
            y = x;
            if (node->price == x->price) {
                x->orders.push_back(order);
                delete node; // Node already exists, clean up unused allocate
                return x;
            }
            // Buy tree descends naturally? Standard BST is fine, we traverse reverse for Buy
            if (node->price < x->price) x = x->left;
            else x = x->right;
        }

        node->parent = y;
        if (y == nullptr) root = node;
        else if (node->price < y->price) y->left = node;
        else y->right = node;

        if (node->parent == nullptr) {
            node->color = BLACK;
            return node;
        }
        if (node->parent->parent == nullptr) return node;

        insertFix(node);
        return node;
    }

    RBNode* getMinimum(RBNode* node) {
        while (node->left != TNULL) node = node->left;
        return node;
    }

    RBNode* getMaximum(RBNode* node) {
        while (node->right != TNULL) node = node->right;
        return node;
    }

    RBNode* getRoot() { return root; }
    RBNode* getTNULL() { return TNULL; }

    // Standard Successor
    RBNode* successor(RBNode* x) {
        if (x->right != TNULL) return getMinimum(x->right);
        RBNode* y = x->parent;
        while (y != nullptr && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }

    // Standard Predecessor
    RBNode* predecessor(RBNode* x) {
        if (x->left != TNULL) return getMaximum(x->left);
        RBNode* y = x->parent;
        while (y != nullptr && x == y->left) {
            x = y;
            y = y->parent;
        }
        return y;
    }
};

// ==========================================
// SECTION 2: BASELINE SYSTEM
// ==========================================
class BaselineOrderBook {
private:
    list<Order> buyOrders;
    list<Order> sellOrders;

public:
    void processOrder(Order newOrder) {
        if (newOrder.type == BUY) {
            // Find lowest SELL <= price
            while (newOrder.quantity > 0) {
                auto bestSell = sellOrders.end();
                for (auto it = sellOrders.begin(); it != sellOrders.end(); ++it) {
                    if (it->price <= newOrder.price) {
                        if (bestSell == sellOrders.end() || it->price < bestSell->price || 
                           (it->price == bestSell->price && it->timestamp < bestSell->timestamp)) {
                            bestSell = it;
                        }
                    }
                }

                if (bestSell != sellOrders.end()) {
                    int matchQty = min(newOrder.quantity, bestSell->quantity);
                    newOrder.quantity -= matchQty;
                    bestSell->quantity -= matchQty;
                    if (bestSell->quantity == 0) sellOrders.erase(bestSell);
                } else {
                    break;
                }
            }
            if (newOrder.quantity > 0) buyOrders.push_back(newOrder);
        } else {
            // Find highest BUY >= price
            while (newOrder.quantity > 0) {
                auto bestBuy = buyOrders.end();
                for (auto it = buyOrders.begin(); it != buyOrders.end(); ++it) {
                    if (it->price >= newOrder.price) {
                        if (bestBuy == buyOrders.end() || it->price > bestBuy->price || 
                           (it->price == bestBuy->price && it->timestamp < bestBuy->timestamp)) {
                            bestBuy = it;
                        }
                    }
                }

                if (bestBuy != buyOrders.end()) {
                    int matchQty = min(newOrder.quantity, bestBuy->quantity);
                    newOrder.quantity -= matchQty;
                    bestBuy->quantity -= matchQty;
                    if (bestBuy->quantity == 0) buyOrders.erase(bestBuy);
                } else {
                    break;
                }
            }
            if (newOrder.quantity > 0) sellOrders.push_back(newOrder);
        }
    }
};

// ==========================================
// SECTION 4: OPTIMIZED SYSTEM & MATCHING ENGINE
// ==========================================
class OptimizedOrderBook {
private:
    RBTree buyTree;  // Keys are prices
    RBTree sellTree; // Keys are prices
    FibonacciHeap expiryHeap;

public:
    OptimizedOrderBook() : buyTree(true), sellTree(false) {}

    void processEvents(long long currentTime) {
        while (!expiryHeap.isEmpty()) {
            FibNode* minEvent = expiryHeap.extractMin();
            if (minEvent->key <= currentTime) {
                // In a real system, we'd mark the order as expired/canceled.
                minEvent->order->quantity = 0; 
                delete minEvent;
            } else {
                expiryHeap.insert(minEvent->key, minEvent->order); // Re-insert and break
                delete minEvent;
                break;
            }
        }
    }

    void processOrder(Order newOrder) {
        if (newOrder.type == BUY) {
            // Match against SELL tree (traverse from minimum ascending)
            RBNode* node = sellTree.getMinimum(sellTree.getRoot());
            while (newOrder.quantity > 0 && node != sellTree.getTNULL() && node->price <= newOrder.price) {
                auto it = node->orders.begin();
                while (it != node->orders.end() && newOrder.quantity > 0) {
                    if (it->quantity == 0) { it = node->orders.erase(it); continue; }
                    
                    int matchQty = min(newOrder.quantity, it->quantity);
                    newOrder.quantity -= matchQty;
                    it->quantity -= matchQty;
                    
                    if (it->quantity == 0) it = node->orders.erase(it);
                    else ++it;
                }
                node = sellTree.successor(node);
            }
            if (newOrder.quantity > 0) {
                buyTree.insertAndGetNode(newOrder.price, newOrder);
            }
        } else {
            // Match against BUY tree (traverse from maximum descending)
            RBNode* node = buyTree.getMaximum(buyTree.getRoot());
            while (newOrder.quantity > 0 && node != buyTree.getTNULL() && node->price >= newOrder.price) {
                auto it = node->orders.begin();
                while (it != node->orders.end() && newOrder.quantity > 0) {
                    if (it->quantity == 0) { it = node->orders.erase(it); continue; }

                    int matchQty = min(newOrder.quantity, it->quantity);
                    newOrder.quantity -= matchQty;
                    it->quantity -= matchQty;
                    
                    if (it->quantity == 0) it = node->orders.erase(it);
                    else ++it;
                }
                node = buyTree.predecessor(node);
            }
            if (newOrder.quantity > 0) {
                sellTree.insertAndGetNode(newOrder.price, newOrder);
            }
        }
    }
};

// ==========================================
// SECTION 5: SCENARIO GENERATOR
// ==========================================
class ScenarioGenerator {
public:
    static vector<Order> generateOrders(int numOrders) {
        vector<Order> orders;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> typeDist(0, 1);
        uniform_real_distribution<> priceDist(10.0, 100.0);
        uniform_int_distribution<> qtyDist(1, 500);

        for (int i = 0; i < numOrders; ++i) {
            Order o;
            o.id = i + 1;
            o.type = (typeDist(gen) == 0) ? BUY : SELL;
            o.price = round(priceDist(gen) * 100.0) / 100.0; // Two decimals
            o.quantity = qtyDist(gen);
            o.timestamp = i;
            o.expiry_time = i + 1000; // Arbitrary expiry
            orders.push_back(o);
        }
        return orders;
    }
};

// ==========================================
// SECTION 6 & 7: PERFORMANCE TESTING & MAIN
// ==========================================
void runPerformanceTest(int size) {
    vector<Order> dataset = ScenarioGenerator::generateOrders(size);
    
    BaselineOrderBook baselineBook;
    OptimizedOrderBook optimizedBook;

    // BASELINE TIMING
    auto startBase = high_resolution_clock::now();
    for (const auto& order : dataset) {
        baselineBook.processOrder(order);
    }
    auto endBase = high_resolution_clock::now();
    double timeBase = duration_cast<microseconds>(endBase - startBase).count() / 1000000.0;

    // OPTIMIZED TIMING
    auto startOpt = high_resolution_clock::now();
    for (const auto& order : dataset) {
        optimizedBook.processOrder(order);
        optimizedBook.processEvents(order.timestamp);
    }
    auto endOpt = high_resolution_clock::now();
    double timeOpt = duration_cast<microseconds>(endOpt - startOpt).count() / 1000000.0;

    double improvement = timeOpt > 0 ? timeBase / timeOpt : 0.0;

    cout << left << setw(10) << size 
         << setw(20) << fixed << setprecision(6) << timeBase 
         << setw(20) << timeOpt 
         << improvement << "x" << endl;
}

int main() {
    cout << "========================================================\n";
    cout << "  STOCK MARKET ENGINE - PERFORMANCE COMPARISON \n";
    cout << "========================================================\n\n";

    cout << left << setw(10) << "Orders" 
         << setw(20) << "Baseline Time (s)" 
         << setw(20) << "Optimized Time (s)" 
         << "Improvement" << endl;
    cout << string(65, '-') << endl;

    vector<int> testSizes = {100, 500, 1000, 2000, 5000, 10000};
    for (int size : testSizes) {
        runPerformanceTest(size);
    }
    
    cout << "\n[Note: With N>1000, $O(N^2)$ baseline degradation becomes apparent vs $O(N \\log N)$ optimized.]\n";
    
    return 0;
}