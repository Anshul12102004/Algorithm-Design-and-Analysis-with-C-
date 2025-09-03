#include <iostream>
#include <vector>
using namespace std;

// DFS function
void dfs(int node, vector<bool>& visited, const vector<vector<int>>& adj) {
    cout << node << " ";        // Visit the current node
    visited[node] = true;
    for (int child : adj[node]) {
        if (!visited[child])
            dfs(child, visited, adj);
    }
}

int main() {
    int n = 10;  // Number of nodes (assume nodes are labeled 1 through 10)
    vector<vector<int>> adj(n + 1);  // 1-based indexing

    // Building the adjacency list 
    adj[1] = {2, 5, 9};
    adj[2] = {3};
    adj[3] = {4};
    adj[4] = {};
    adj[5] = {6, 8};
    adj[6] = {7};
    adj[7] = {};
    adj[8] = {};
    adj[9] = {10};
    adj[10] = {};

    vector<bool> visited(n + 1, false);

    cout << "DFS Traversal starting from node 1: ";
    dfs(1, visited, adj);
    cout << endl;

    return 0;
}