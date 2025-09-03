#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 6 // Number of vertices

int minKey(const vector<int>& key, const vector<bool>& mstSet) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primMST(int graph[V][V]) {
    vector<int> parent(V); // Stores MST
    vector<int> key(V, INT_MAX); // Key values to pick min weight
    vector<bool> mstSet(V, false); // Vertex included in MST

    key[0] = 0;      // Start from vertex 0 (A)
    parent[0] = -1;  // First node is root

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the constructed MST
    char name[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int total_weight = 0;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << name[parent[i]] << " - " << name[i] << " \t"
             << graph[i][parent[i]] << endl;
        total_weight += graph[i][parent[i]];
    }
    cout << "Total weight of MST: " << total_weight << endl;
}

int main() {
    int graph[V][V] = {
        { 0, 1, 0, 3, 2, 0},
        { 1, 0, 3, 0, 6, 5},
        { 0, 3, 0, 0, 0, 4},
        { 3, 0, 0, 0, 3, 0},
        { 2, 6, 0, 3, 0, 2},
        { 0, 5, 4, 0, 2, 0}
    };

    primMST(graph);
    return 0;
}
