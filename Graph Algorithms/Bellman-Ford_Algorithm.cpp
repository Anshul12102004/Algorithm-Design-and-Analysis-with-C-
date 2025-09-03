#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int from, to, weight;
};

int main() {
    int V = 5; // Number of vertices (s,t,x,y,z)
    int E = 10; // Number of edges

    // List of all edges
    vector<Edge> edges = {
        {0,1,6},   // s->t
        {0,3,7},   // s->y
        {1,2,5},   // t->x
        {1,3,8},   // t->y
        {1,4,-4},  // t->z
        {2,1,-2},  // x->t
        {3,2,-3},  // y->x
        {3,4,9},   // y->z
        {4,0,2},   // z->s
        {4,2,7}    // z->x
    };

    int src = 0; // Source is 's' (0)

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax edges V-1 times
    for(int i=1; i<V; ++i){
        for(auto &e : edges){
            if(dist[e.from] != INT_MAX && dist[e.from] + e.weight < dist[e.to]){
                dist[e.to] = dist[e.from] + e.weight;
            }
        }
    }

    // Check for negative-weight cycles
    bool hasNegativeCycle = false;
    for(auto &e : edges) {
        if(dist[e.from] != INT_MAX && dist[e.from] + e.weight < dist[e.to]){
            hasNegativeCycle = true;
            break;
        }
    }

    cout << "Vertex\tDistance from Source (s)" << endl;
    char names[] = {'s','t','x','y','z'};
    for(int i=0; i<V; ++i) {
        cout << names[i] << "\t";
        if(dist[i]==INT_MAX) cout << "INF";
        else cout << dist[i];
        cout << endl;
    }

    if(hasNegativeCycle)
        cout << "Graph contains a negative-weight cycle!" << endl;

    return 0;
}
