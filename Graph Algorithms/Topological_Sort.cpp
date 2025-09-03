#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    const int N = 6; // Number of nodes (0..5)
    vector<vector<int>> adj(N);
    // Add edges as per the diagram
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {};
    adj[4] = {5};
    adj[5] = {1, 2};

    // Step 2: Compute indegrees
    vector<int> indegree(N, 0);
    for (int u = 0; u < N; ++u)
        for (int v : adj[u])
            indegree[v]++;

    // Step 3: Push all nodes with indegree 0 to queue
    queue<int> q;
    for (int i = 0; i < N; ++i)
        if (indegree[i] == 0)
            q.push(i);

    // Step 4: Perform Kahn's Algorithm
    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }

    // Step 5: Print the Topological Order
    if (topo.size() != N) {
        cout << "The graph is not a DAG (contains a cycle)." << endl;
    } else {
        cout << "Topological Order (Kahn's Algorithm): ";
        for (int x : topo) cout << x << " ";
        cout << endl;
    }

    return 0;
}
