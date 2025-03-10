#include <iostream>
#include <vector>

using namespace std;

// Adjacency list
vector<vector<int>> adj; 
vector<bool> visited;
vector<int> parent;
int cycle_start = -1;
int cycle_end = -1;

// DFS Function; current node v and parent of current node
bool dfs(int v, int par) {
    // Mark v as visited; store its parent
    visited[v] = true;
    parent[v] = par;

    // Iterate through all neighbor of node v
    for (int neighbor : adj[v]) {
        // Ignore if neighbor is parent of v
        if (neighbor == par) {
            continue;
        }
        
        // Visited neighbor has different parent
        if (visited[neighbor]) {
            // Node where the cycle starts and completed the cycle
            cycle_start = neighbor;
            cycle_end = v;
            return true;
        }

        parent[neighbor] = v;
        if (dfs(neighbor, v)) {
            return true;
        }
    }
    return false;
}

void findCycle(int n) {
    // Mark all nodes as not visited and reset parents
    visited.assign(n, false);
    parent.assign(n, -1);

    // Iterate through all nodes
    for (int v = 0; v < n; v++) {
        // Start DFS on v if not visited
        if (!visited[v] && dfs(v, -1)) {
            break;
        }
    }

    // Check for cycle
    if (cycle_start == -1) {
        cout << "No cycle found." << endl;
        return;
    }

    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
        cycle.push_back(v);
    }
    cycle.push_back(cycle_start);

    cout << "Cycle found: ";
    for (int v : cycle) cout << v << " ";
    cout << endl;
}

int main() {
    int n = 5; // Number of nodes
    adj.resize(n);

    // Adding edges (Example graph with a cycle)
    adj[0].push_back(1); adj[1].push_back(0);
    adj[1].push_back(2); adj[2].push_back(1);
    adj[2].push_back(3); adj[3].push_back(2);
    adj[3].push_back(4); adj[4].push_back(3);
    adj[4].push_back(1); adj[1].push_back(4);

    findCycle(n);

    return 0;
}