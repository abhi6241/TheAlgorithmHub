#include <iostream>

const int MAX_KEYS = 3;         // For a degree-2 B-Tree (Minimum degree t=2)
const int MAX_CHILDREN = 4;

struct Node {
    int n;                      // Current number of keys
    int key[MAX_KEYS];          // Array of keys
    Node* child[MAX_CHILDREN];  // Pointers to children
    bool leaf;                  // True if leaf, false otherwise

    Node(bool isLeaf) {
        n = 0;
        leaf = isLeaf;
        for (int i = 0; i < MAX_CHILDREN; i++) child[i] = nullptr;
    }
};

Node* BtreeSearch(Node* x, int k) {
    int i = 0;
    // Linear search within the node
    while (i < x->n && k > x->key[i]) {
        i++;
    }

    // Check if the key is found in this node
    if (i < x->n && k == x->key[i]) {
        return x;
    }

    // If not found and this is a leaf node
    if (x->leaf) {
        return nullptr;
    }

    // Recurse to the appropriate child
    return BtreeSearch(x->child[i], k);
}

int main() {
    // Manually creating a simple B-Tree node for testing
    Node* root = new Node(false);
    root->key[0] = 20;
    root->n = 1;

    Node* leftChild = new Node(true);
    leftChild->key[0] = 10;
    leftChild->n = 1;

    Node* rightChild = new Node(true);
    rightChild->key[0] = 30;
    rightChild->n = 1;

    root->child[0] = leftChild;
    root->child[1] = rightChild;

    int k = 30;
    Node* result = BtreeSearch(root, k);

    if (result != nullptr) {
        std::cout << "Key " << k << " found in node at " << result << std::endl;
    } else {
        std::cout << "Key not found." << std::endl;
    }

    return 0;
}