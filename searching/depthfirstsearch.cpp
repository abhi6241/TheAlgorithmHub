#include <iostream>
#include <vector>

using namespace std;

// Modified to return bool to signal when the target is found
bool dfsSearchRec(vector<vector<int>> &adj, vector<bool> &visited, int s, int target) {
    // 1. Check if current node is the one we want
    if (s == target) return true;

    visited[s] = true;

    // 2. Recur for neighbors
    for (int i : adj[s]) {
        if (!visited[i]) {
            // If the search in the branch returns true, stop and pass it up
            if (dfsSearchRec(adj, visited, i, target)) {
                return true;
            }
        }
    }
    
    return false; // Target not found in this branch
}

bool search(vector<vector<int>> &adj, int startNode, int target) {
    vector<bool> visited(adj.size(), false);
    return dfsSearchRec(adj, visited, startNode, target);
}

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    
    int target = 3;
    if (search(adj, 0, target)) {
        cout << "Target " << target << " is reachable from 0." << endl;
    } else {
        cout << "Target " << target << " is NOT reachable." << endl;
    }

    return 0;
}