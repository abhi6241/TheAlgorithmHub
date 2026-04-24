#include <iostream>
#include <string>
#include <vector>

// Structure for a Node in the linked list
struct Node {
    std::string key;
    int value;
    Node* next;

    Node(std::string k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
private:
    static const int TABLE_SIZE = 11; // Using a prime number helps distribute keys better
    Node* table[TABLE_SIZE];

    // Simple Hash Function (Polynomial rolling hash logic)
    int hashFunction(std::string key) {
        unsigned long hash = 0;
        for (char c : key) {
            hash = (hash * 31) + c;
        }
        return hash % TABLE_SIZE;
    }

public:
    HashTable() {
        // Initialize all buckets to nullptr
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    // 1. INSERT: O(1) average
    void insert(std::string key, int value) {
        int index = hashFunction(key);
        
        // Check if key already exists to update it
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        // If not found, insert at the head of the list (Fastest)
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    // 2. SEARCH: O(1) average, O(n) worst case
    int search(std::string key) {
        int index = hashFunction(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                return current->value; // Match found
            }
            current = current->next;
        }
        return -1; // Key not found
    }

    // 3. REMOVE: O(1) average
    void remove(std::string key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr && current->key != key) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) return; // Key not found

        if (prev == nullptr) {
            // Removing the head node
            table[index] = current->next;
        } else {
            // Unlinking node from middle or end
            prev->next = current->next;
        }

        delete current;
    }

    ~HashTable() {
        // Cleanup memory
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable myDict;

    myDict.insert("UserA", 500);
    myDict.insert("UserB", 1200);
    myDict.insert("UserC", 750);

    std::string query = "UserB";
    int score = myDict.search(query);

    if (score != -1) {
        std::cout << "Found " << query << " with score: " << score << std::endl;
    } else {
        std::cout << query << " not found." << std::endl;
    }

    myDict.remove("UserB");
    std::cout << "After removal, searching for UserB: " << myDict.search("UserB") << std::endl;

    return 0;
}