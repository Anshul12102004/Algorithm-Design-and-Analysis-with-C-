#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

// Disjoint Set Union (Union-Find)
struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }
    void unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return;
        if (rank[xr] < rank[yr]) parent[xr] = yr;
        else {
            parent[yr] = xr;
            if (rank[xr] == rank[yr]) rank[xr]++;
        }
    }
};

int main() {
    int V = 6; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 1},
        {0, 3, 4},
        {0, 4, 7},
        {1, 2, 5},
        {1, 4, 3},
        {1, 5, 6},
        {2, 5, 9},
        {3, 4, 8},
        {4, 5, 2}
    };

    DSU dsu(V);
    int mst_weight = 0;
    vector<Edge> mst_edges;

    int components = V;

    while (components > 1) {
        vector<int> cheapest(V, -1);
        // Find cheapest edge for each component
        for (int i = 0; i < edges.size(); ++i) {
            int set1 = dsu.find(edges[i].src);
            int set2 = dsu.find(edges[i].dest);
            if (set1 != set2) {
                if (cheapest[set1] == -1 || edges[i].weight < edges[cheapest[set1]].weight)
                    cheapest[set1] = i;
                if (cheapest[set2] == -1 || edges[i].weight < edges[cheapest[set2]].weight)
                    cheapest[set2] = i;
            }
        }
        // Add edges and unite components
        for (int i = 0; i < V; ++i) {
            if (cheapest[i] != -1) {
                int set1 = dsu.find(edges[cheapest[i]].src);
                int set2 = dsu.find(edges[cheapest[i]].dest);
                if (set1 != set2) {
                    dsu.unite(set1, set2);
                    mst_weight += edges[cheapest[i]].weight;
                    mst_edges.push_back(edges[cheapest[i]]);
                    components--;
                }
            }
        }
    }

    // Output
    char label[] = {'A','B','C','D','E','F'};
    cout << "Edges in Boruvka's MST:" << endl;
    for (auto &e : mst_edges)
        cout << label[e.src] << " - " << label[e.dest] << " : " << e.weight << endl;
    cout << "Total weight of MST: " << mst_weight << endl;

    return 0;
}
