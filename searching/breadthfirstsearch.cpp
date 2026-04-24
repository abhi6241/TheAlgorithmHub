#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * BFS Search
 * @param adj The adjacency list of the graph
 * @param startNode The vertex to start searching from
 * @param target The value we are looking for
 * @return true if target is found, false otherwise
 */
bool bfsSearch(vector<vector<int>> &adj, int startNode, int target) {
    int V = adj.size();
    if (V == 0) return false;

    // Check if the start node is already our target
    if (startNode == target) return true;

    vector<bool> visited(V, false);
    queue<int> q;

    // Initialize search
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // Explore all neighbors of the current node
        for (int neighbor : adj[curr]) {
            // Found the target!
            if (neighbor == target) {
                return true; 
            }

            // If not visited, add to queue to explore its neighbors later
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return false; // Target not reachable from startNode
}

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);

    int target = 5;
    if (bfsSearch(adj, 0, target)) {
        cout << "Target " << target << " found!" << endl;
    } else {
        cout << "Target " << target << " not reachable." << endl;
    }

    return 0;
}