#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int root, const vector<vector<int>>& adj, int n) {
    vector<bool> visited(n + 1, false);
    queue<int> q;

    visited[root] = true;
    q.push(root);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int child : adj[node]) {
            if (!visited[child]) {
                visited[child] = true;
                q.push(child);
            }
        }
    }
}

int main() {
    int n = 10;  // Number of nodes
    vector<vector<int>> adj(n + 1);

    // Building the adjacency list
    adj[1] = {2, 3, 4};
    adj[2] = {5};
    adj[3] = {6, 7};
    adj[4] = {8};
    adj[5] = {9};
    adj[6] = {10};
    // Nodes 7, 8, 9, 10 have no children

    cout << "BFS Traversal starting from node 1: ";
    bfs(1, adj, n);
    cout << endl;

    return 0;
}
