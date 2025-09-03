#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int INF = 1e9; // Use a large number as infinity

int main() {
    int n = 4; // Number of vertices
    // Adjacency matrix initialized with INF (no edge), 0 for self-loop
    vector<vector<int>> dist = {
        {0,   4,  -2, INF},
        {INF, 0,   3,  -1},
        {INF, INF, 0,   2},
        {INF, INF, INF, 0}
    };

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Print shortest distance matrix
    cout << "All-pairs shortest path matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << dist[i][j];
        }
        cout << endl;
    }

    return 0;
}
