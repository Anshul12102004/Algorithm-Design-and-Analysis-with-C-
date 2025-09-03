#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Disjoint Set Union (DSU) for cycle detection
struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        return (parent[x] == x) ? x : (parent[x] = find(parent[x]));
    }
    bool unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return false;
        if (rank[xr] < rank[yr]) parent[xr] = yr;
        else {
            parent[yr] = xr;
            if (rank[xr] == rank[yr]) rank[xr]++;
        }
        return true;
    }
};
// ---------------------------------------------------------------------

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int main() {
    // List all edges: {from, to, weight}
    vector<Edge> edges = {
        {0, 1, 3}, // a-b
        {0, 4, 1}, // a-e
        {1, 2, 5}, // b-c
        {1, 4, 4}, // b-e
        {2, 3, 2}, // c-d
        {4, 3, 7}, // e-d
        {4, 2, 6}  // e-c
    };
    int n = 5; // Number of vertices

    // Kruskal's Algorithm
    sort(edges.begin(), edges.end()); // Sort edges by weight
    DSU dsu(n);
    vector<Edge> mst;
    int total_weight = 0;

    for (const auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            total_weight += e.w;
        }
    }

    // Output the MST
    char name[] = {'a', 'b', 'c', 'd', 'e'};
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto& e : mst) {
        cout << name[e.u] << " - " << name[e.v] << " : " << e.w << endl;
    }
    cout << "Total weight of MST: " << total_weight << endl;
    return 0;
}
