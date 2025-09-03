#include <iostream>
using namespace std;

#define N 4 // Number of vertices (a, b, c, d)

void warshall(int graph[N][N]) {
    // Initialize reachability matrix as given adjacency matrix
    int reach[N][N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            reach[i][j] = graph[i][j];

    // Apply Warshall's Algorithm
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);

    // Print the reachability (transitive closure) matrix
    cout << "Transitive closure matrix (1: reachable, 0: not reachable):\n";
    char nodes[] = {'a','b','c','d'};
    cout << "  ";
    for (int j = 0; j < N; ++j) cout << nodes[j] << " ";
    cout << endl;
    for (int i = 0; i < N; ++i) {
        cout << nodes[i] << " ";
        for (int j = 0; j < N; ++j)
            cout << reach[i][j] << " ";
        cout << endl;
    }
}

int main() {
    // Adjacency matrix
    int graph[N][N] = {
        // a  b  c  d
        0, 1, 0, 1, // a
        0, 0, 0, 1, // b
        1, 0, 0, 0, // c
        0, 0, 1, 0  // d
    };

    warshall(graph);
    return 0;
}
