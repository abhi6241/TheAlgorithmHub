#include <iostream>
#include <string>

// Structure for a Node in the Linked List (Chaining)
struct Node {
    std::string key;
    int value;
    Node* next;

    Node(std::string k, int v) : key(k), value(v), next(nullptr) {}
};

const int TABLE_SIZE = 10;
Node* hashTable[TABLE_SIZE] = {nullptr}; // Initialize table with null pointers

// 1. Hash Function (Simple string hashing)
int hashFunction(std::string key) {
    int hash = 0;
    for (char c : key) {
        hash += c;
    }
    return hash % TABLE_SIZE;
}

// 2. Insert Function
void insert(std::string key, int value) {
    int index = hashFunction(key);
    Node* newNode = new Node(key, value);

    // If bucket is empty, insert as head
    if (hashTable[index] == nullptr) {
        hashTable[index] = newNode;
    } else {
        // Collision: Add to the front of the list (Chaining)
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

// 3. SEARCH FUNCTION
// Returns the value if found, or -1 if not found
int search(std::string key) {
    int index = hashFunction(key);
    Node* current = hashTable[index];

    // Traverse the linked list at this bucket
    while (current != nullptr) {
        if (current->key == key) {
            return current->value; // Found it!
        }
        current = current->next;
    }

    return -1; // Key doesn't exist
}

int main() {
    // Adding some data
    insert("Apple", 100);
    insert("Banana", 200);
    insert("Grape", 300);
    insert("Cherry", 400); // This might collide depending on hash

    std::string target = "Banana";
    int result = search(target);

    if (result != -1) {
        std::cout << "Key: " << target << " | Value: " << result << std::endl;
    } else {
        std::cout << "Key not found." << std::endl;
    }

    return 0;
}