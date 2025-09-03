#include <iostream>
#include <vector>
using namespace std;
const int MAX_VERTICES = 100;
vector<vector<int>> graph(MAX_VERTICES, vector<int>(MAX_VERTICES, 0));
vector<bool> included(MAX_VERTICES, false);
// Function to find Vertex Cover using the APPROX-VERTEX_COVER algorithm
void approxVertexCover(int vertices, int edges) {
   vector<vector<bool>> edgesRemaining(vertices, vector<bool>(vertices, false));
   for (int i = 0; i < vertices; i++) {
      for (int j = 0; j < vertices; j++) {
         edgesRemaining[i][j] = graph[i][j];
      }
   }
   while (edges > 0) {
      int u, v;
      for (int i = 0; i < vertices; i++) {
         for (int j = 0; j < vertices; j++) {
            if (edgesRemaining[i][j]) {
               u = i;
               v = j;
               break;
            }
         }
      }
      included[u] = included[v] = true;
      for (int i = 0; i < vertices; i++) {
         edgesRemaining[u][i] = edgesRemaining[i][u] = false;
         edgesRemaining[v][i] = edgesRemaining[i][v] = false;
      }
      edges--;
   }
}
int main() {
   int vertices = 8;
   int edges = 10;
   int edgesData[10][2] = {
   {1, 6}, {1, 2}, {1, 4}, {2, 3}, {2, 4},
   {6, 7}, {4, 7}, {7, 8}, {3, 5}, {8, 5}};
   for (int i = 0; i < edges; i++) {
      int u = edgesData[i][0];
      int v = edgesData[i][1];
      graph[u][v] = graph[v][u] = 1;
   }
   approxVertexCover(vertices, edges);
   cout << "Vertex Cover: ";
   for (int i = 1; i <= vertices; i++) {
      if (included[i]) {
         cout << i << " ";
      }
   }
   cout << endl;
   return 0;
}