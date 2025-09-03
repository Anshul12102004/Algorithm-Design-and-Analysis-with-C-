#include<iostream>
#include<climits>
using namespace std;
int min_dist(int dist[], bool visited[]){ // finding minimum dist
   int minimum=INT_MAX,ind;
   for(int k=0; k<6; k++) {
      if(visited[k]==false && dist[k]<=minimum) {
         minimum=dist[k];
         ind=k;
      }
   }
   return ind;
}
void greedy_dijsktra(int graph[6][6],int src){
   int dist[6];
   bool visited[6];
   for(int k = 0; k<6; k++) {
      dist[k] = INT_MAX;
      visited[k] = false;
   }
   dist[src] = 0; // Source vertex dist is set 0
   for(int k = 0; k<6; k++) {
      int m=min_dist(dist,visited);
      visited[m]=true;
      for(int k = 0; k<6; k++) {

         // updating the dist of neighbouring vertex
         if(!visited[k] && graph[m][k] && dist[m]!=INT_MAX && dist[m]+graph[m][k]<dist[k])
            dist[k]=dist[m]+graph[m][k];
      }
   }
   cout<<"Vertex\t\tdist from source vertex"<<endl;
   for(int k = 0; k<6; k++) {
      char str=65+k;
      cout<<str<<"\t\t\t"<<dist[k]<<endl;
   }
}
int main(){
   int graph[6][6]= {
      {0, 1, 2, 0, 0, 0},
      {1, 0, 0, 5, 1, 0},
      {2, 0, 0, 2, 3, 0},
      {0, 5, 2, 0, 2, 2},
      {0, 1, 3, 2, 0, 1},
      {0, 0, 0, 2, 1, 0}
   };
   greedy_dijsktra(graph,0);
   return 0;
}