#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii; // (distance, vertex)

void dijkstra(int n, int start, const vector<vector<pii>>& adj) {
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [weight, v] : adj[u]) {
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << i << "\t";
        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }
}

int main() {
    int n = 6; // number of nodes (1-based)
    vector<vector<pii>> adj(n + 1);

    // Edges: adj[src].push_back({weight, dest})
    adj[1].push_back({7, 2});
    adj[1].push_back({9, 6});
    adj[1].push_back({14, 3});
    adj[2].push_back({7, 1});
    adj[2].push_back({10, 3});
    adj[2].push_back({15, 4});
    adj[3].push_back({14, 1});
    adj[3].push_back({10, 2});
    adj[3].push_back({2, 6});
    adj[3].push_back({11, 4});
    adj[4].push_back({15, 2});
    adj[4].push_back({11, 3});
    adj[4].push_back({6, 5});
    adj[5].push_back({6, 4});
    adj[5].push_back({9, 6});
    adj[6].push_back({9, 1});
    adj[6].push_back({2, 3});
    adj[6].push_back({9, 5});

    int start = 1; // starting from node 'a', which is 1
    dijkstra(n, start, adj);

    return 0;
}
