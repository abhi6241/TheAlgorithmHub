#include <iostream>
#include <string>

using namespace std;

// Node structure with explicit pointers for tree navigation
struct Node {
    int data;
    string color; // "RED" or "BLACK"
    Node *left, *right, *parent;

    Node(int data) : data(data), color("RED"), 
                     left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;
    Node* NIL; // Sentinel node used to represent leaves (always BLACK)

    // --- Rotations: Essential for maintaining tree balance ---

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != NIL) y->left->parent = x;
        y->parent = x->parent;

        if (x->parent == nullptr)      root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else                          x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;

        if (y->right != NIL) y->right->parent = x;
        y->parent = x->parent;

        if (x->parent == nullptr)       root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else                           x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    // --- RB Fix-up: Resolves Double-Red violations ---

    void fixInsert(Node* k) {
        // Continue while the parent is Red (violates RB property)
        while (k != root && k->parent->color == "RED") {
            if (k->parent == k->parent->parent->left) {
                Node* uncle = k->parent->parent->right;

                if (uncle->color == "RED") {            
                    // Case 1: Uncle is Red -> Recolor parent, uncle, and grandparent
                    k->parent->color = "BLACK";
                    uncle->color = "BLACK";
                    k->parent->parent->color = "RED";
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {       
                        // Case 2: Triangle shape -> Left rotate parent to form a line
                        k = k->parent;
                        leftRotate(k);
                    }
                    // Case 3: Line shape -> Recolor and right rotate grandparent
                    k->parent->color = "BLACK";        
                    k->parent->parent->color = "RED";
                    rightRotate(k->parent->parent);
                }
            } else {                                   
                // Mirror Case: Parent is the right child
                Node* uncle = k->parent->parent->left;

                if (uncle->color == "RED") {
                    k->parent->color = "BLACK";
                    uncle->color = "BLACK";
                    k->parent->parent->color = "RED";
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = "BLACK";
                    k->parent->parent->color = "RED";
                    leftRotate(k->parent->parent);
                }
            }
        }
        root->color = "BLACK"; // Root must always be Black
    }

public:
    RedBlackTree() {
        NIL = new Node(0);
        NIL->color = "BLACK";
        NIL->left = NIL->right = NIL;
        root = NIL;
    }

    void insert(int data) {
        Node* node = new Node(data);
        node->left = node->right = NIL;

        Node* parent = nullptr;
        Node* current = root;

        // Step 1: Standard Binary Search Tree insertion
        while (current != NIL) {
            parent = current;
            if (node->data < current->data) current = current->left;
            else current = current->right;
        }

        node->parent = parent;

        if (parent == nullptr)      root = node;
        else if (node->data < parent->data) parent->left = node;
        else                               parent->right = node;

        // Step 2: Handle edge cases and fix RB properties
        if (node->parent == nullptr) {
            node->color = "BLACK";
            return;
        }
        if (node->parent->parent == nullptr) return;

        fixInsert(node);
    }

    void inorder(Node* node) {
        if (node != NIL) {
            inorder(node->left);
            cout << node->data << "(" << node->color << ") ";
            inorder(node->right);
        }
    }

    Node* getRoot() { return root; }
};

int main() {
    RedBlackTree rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);

    cout << "Inorder Traversal -> ";
    rbt.inorder(rbt.getRoot());
    cout << endl;

    return 0;
}