#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 1. Recursive Approach
Node* searchRecursive(Node* root, int key) {
    // Base Case: root is null or key is present at root
    if (root == nullptr || root->data == key) {
        return root;
    }

    // Key is greater than root's data
    if (key > root->data) {
        return searchRecursive(root->right, key);
    }

    // Key is smaller than root's data
    return searchRecursive(root->left, key);
}

// 2. Iterative Approach (More memory efficient)
Node* searchIterative(Node* root, int key) {
    while (root != nullptr && root->data != key) {
        if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return root;
}

int main() {
    // Creating a simple BST
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);

    int target = 40;
    Node* result = searchIterative(root, target);

    if (result) {
        std::cout << "Element " << target << " found in the tree.";
    } else {
        std::cout << "Element " << target << " not found.";
    }

    return 0;
}