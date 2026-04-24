#include <iostream>
#include <algorithm>

// Structure for a node
struct Node {
    int data;
    int height;
    Node *left, *right;

    Node(int val) : data(val), height(1), left(nullptr), right(nullptr) {}
};

// Utility to get height of the tree
int getHeight(Node* n) {
    return (n == nullptr) ? 0 : n->height;
}

// Get Balance factor of node N
int getBalance(Node* n) {
    return (n == nullptr) ? 0 : getHeight(n->left) - getHeight(n->right);
}

// Right Rotate (used for Left-Left imbalance)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // New root
}

// Left Rotate (used for Right-Right imbalance)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // New root
}

// Insertion function that maintains balance
Node* insert(Node* node, int data) {
    // 1. Standard BST insertion
    if (node == nullptr) return new Node(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // Duplicate values not allowed

    // 2. Update height of this ancestor node
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    // 3. Get balance factor to check for imbalance
    int balance = getBalance(node);

    // Case 1: Left Left
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Case 2: Right Right
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Case 3: Left Right
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right Left
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// SEARCH FUNCTION
Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int main() {
    Node* root = nullptr;

    // Building the tree
    // Inserting values that would normally create a skewed tree (10, 20, 30)
    // The AVL rotations will keep it balanced.
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    int target = 25;
    Node* found = search(root, target);

    if (found)
        std::cout << "Element " << target << " found in the AVL Tree." << std::endl;
    else
        std::cout << "Element " << target << " not found." << std::endl;

    return 0;
}