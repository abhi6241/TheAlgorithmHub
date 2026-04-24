#include <iostream>

const int MAX_KEYS = 3;
const int MAX_CHILDREN = 4;

struct Node {
    int n;                          // Number of keys
    int key[MAX_KEYS];              // Keys (Internal nodes = guides, Leaves = actual data)
    Node* child[MAX_CHILDREN];      // Children pointers
    Node* next;                     // Pointer to next leaf node (Linked list)
    bool leaf;

    Node(bool isLeaf) : n(0), leaf(isLeaf), next(nullptr) {
        for (int i = 0; i < MAX_CHILDREN; i++) child[i] = nullptr;
    }
};

/**
 * B+ Tree Search
 * In a B+ Tree, we always traverse down to the leaf level.
 */
Node* BPlusTreeSearch(Node* x, int k) {
    if (x == nullptr) return nullptr;

    int i = 0;
    // Find the first key greater than or equal to k
    while (i < x->n && k > x->key[i]) {
        i++;
    }

    // If this is a leaf node, check if the key exists here
    if (x->leaf) {
        if (i < x->n && x->key[i] == k) {
            return x; // Found the leaf containing the key
        }
        return nullptr; // Key not present in the leaf
    }

    // If internal node, move to the child. 
    // Note: If k == x->key[i], we move to child[i+1] in some implementations, 
    // but standard B+ logic usually moves to child[i] where keys >= x->key[i] reside.
    return BPlusTreeSearch(x->child[i], k);
}

int main() {
    // Basic setup for demonstration:
    // Root (Internal): Key 20
    // Child 0 (Leaf): Keys 5, 10
    // Child 1 (Leaf): Keys 20, 25
    
    Node* root = new Node(false);
    root->key[0] = 20;
    root->n = 1;

    Node* leaf1 = new Node(true);
    leaf1->key[0] = 5;
    leaf1->key[1] = 10;
    leaf1->n = 2;

    Node* leaf2 = new Node(true);
    leaf2->key[0] = 20;
    leaf2->key[1] = 25;
    leaf2->n = 2;

    root->child[0] = leaf1;
    root->child[1] = leaf2;
    leaf1->next = leaf2; // Linked list connection

    int target = 20;
    Node* result = BPlusTreeSearch(root, target);

    if (result) {
        std::cout << "Key " << target << " found in leaf node." << std::endl;
    } else {
        std::cout << "Key " << target << " not found." << std::endl;
    }

    return 0;
}