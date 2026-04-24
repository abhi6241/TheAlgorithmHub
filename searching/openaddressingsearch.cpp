#include <iostream>
#include <vector>

enum ProbeType { LINEAR, QUADRATIC, DOUBLE };

struct HashEntry {
    int key;
    int value;
    bool isOccupied;
    bool isDeleted;

    HashEntry() : key(-1), value(-1), isOccupied(false), isDeleted(false) {}
};

class OpenAddressingTable {
private:
    int size;
    std::vector<HashEntry> table;
    ProbeType type;

    // Primary Hash
    int hash1(int key) { return key % size; }

    // Secondary Hash for Double Hashing (must be non-zero)
    int hash2(int key) { return 7 - (key % 7); }

    int getProbe(int key, int i) {
        if (type == LINEAR) {
            return (hash1(key) + i) % size;
        } else if (type == QUADRATIC) {
            return (hash1(key) + i * i) % size;
        } else { // DOUBLE
            return (hash1(key) + i * hash2(key)) % size;
        }
    }

public:
    OpenAddressingTable(int s, ProbeType t) : size(s), type(t) {
        table.resize(size);
    }

    void insert(int key, int value) {
        for (int i = 0; i < size; i++) {
            int index = getProbe(key, i);
            
            // Insert if empty or marked as deleted (Tombstone)
            if (!table[index].isOccupied || table[index].isDeleted) {
                table[index].key = key;
                table[index].value = value;
                table[index].isOccupied = true;
                table[index].isDeleted = false;
                return;
            }
            
            // Update value if key already exists
            if (table[index].key == key && !table[index].isDeleted) {
                table[index].value = value;
                return;
            }
        }
        std::cout << "Table Full!" << std::endl;
    }

    int search(int key) {
        for (int i = 0; i < size; i++) {
            int index = getProbe(key, i);
            
            // If we hit a truly empty slot, key isn't here
            if (!table[index].isOccupied && !table[index].isDeleted) return -1;

            if (table[index].isOccupied && !table[index].isDeleted && table[index].key == key) {
                return table[index].value;
            }
        }
        return -1;
    }

    void remove(int key) {
        for (int i = 0; i < size; i++) {
            int index = getProbe(key, i);
            if (!table[index].isOccupied && !table[index].isDeleted) return;

            if (table[index].isOccupied && !table[index].isDeleted && table[index].key == key) {
                table[index].isDeleted = true; // Mark as Tombstone
                std::cout << "Key " << key << " deleted." << std::endl;
                return;
            }
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i].isOccupied && !table[i].isDeleted)
                std::cout << "[" << i << "]: " << table[i].key << " ";
            else if (table[i].isDeleted)
                std::cout << "[" << i << "]: <TOMB> ";
            else
                std::cout << "[" << i << "]: EMPTY ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Testing Linear Probing
    std::cout << "--- Linear Probing ---" << std::endl;
    OpenAddressingTable ht(10, LINEAR);
    ht.insert(5, 500);
    ht.insert(15, 1500); // Collision at index 5
    ht.insert(25, 2500); // Collision at index 5
    ht.display();
    
    ht.remove(15);
    ht.display();
    
    std::cout << "Search 25: " << ht.search(25) << std::endl;

    return 0;
}