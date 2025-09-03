#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const { return w < other.w; }
};

int find(vector<int>& parent, int i) {
    return (parent[i] == i) ? i : parent[i] = find(parent, parent[i]);
}
void unite(vector<int>& parent, vector<int>& rank, int u, int v) {
    int pu = find(parent, u), pv = find(parent, v);
    if (pu != pv) {
        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pu] > rank[pv]) parent[pv] = pu;
        else { parent[pv] = pu; rank[pu]++; }
    }
}

int main() {
    int n = 5;
    vector<char> name = {'a','b','c','d','e'};

    // Original Graph (from textbook)
    vector<vector<int>> dist = {
        {0, 4, 8, 9,12}, // a
        {4, 0, 6, 8,11}, // b
        {8, 6, 0,10,11}, // c
        {9, 8,10, 0, 7}, // d
        {12,11,11, 7, 0} // e
    };

    cout << "Original Graph Edges:\n";
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            cout << name[i] << "-" << name[j] << "=" << dist[i][j] << "\n";

    // Step 1: MST using Kruskal
    vector<Edge> edges, mst;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            edges.push_back({i,j,dist[i][j]});
    sort(edges.begin(), edges.end());
    vector<int> parent(n), rank(n,0);
    iota(parent.begin(), parent.end(), 0);
    for(auto &e : edges)
        if(find(parent,e.u)!=find(parent,e.v)){
            unite(parent,rank,e.u,e.v);
            mst.push_back(e);
        }

    cout << "\nMST:\n";
    for(auto &e: mst) cout << name[e.u] << "-" << name[e.v] << "=" << e.w << "\n";

    // Step 2: Find odd degree vertices
    vector<int> degree(n,0);
    for(auto &e: mst){ degree[e.u]++; degree[e.v]++; }
    vector<int> odd;
    for(int i=0;i<n;i++) if(degree[i]%2==1) odd.push_back(i);

    cout << "\nOdd Degree Vertices: ";
    for(int v: odd) cout << name[v] << " ";
    cout << "\n";

    // Step 3: Minimum Weight Perfect Matching (greedy)
    vector<pair<int,int>> matching;
    vector<bool> used(n,false);
    for(int i=0;i<(int)odd.size();i++){
        if(used[odd[i]]) continue;
        int u=odd[i], best=-1, w=1e9;
        for(int j=i+1;j<(int)odd.size();j++){
            if(used[odd[j]]) continue;
            if(dist[u][odd[j]]<w){w=dist[u][odd[j]]; best=odd[j];}
        }
        if(best!=-1){
            matching.push_back({u,best});
            used[u]=used[best]=true;
        }
    }

    cout << "\nMinimum Weight Perfect Matching:\n";
    for(auto &p: matching)
        cout << name[p.first] << "-" << name[p.second] << "=" << dist[p.first][p.second] << "\n";

    // Step 4: Eulerian Multigraph = MST + Matching
    vector<pair<int,int>> multigraph;
    for(auto &e:mst) multigraph.push_back({e.u,e.v});
    for(auto &p:matching) multigraph.push_back(p);

    cout << "\nEulerian Multigraph Edges:\n";
    for(auto &e:multigraph) cout << name[e.first] << "-" << name[e.second] << "\n";

    // Step 5: Euler Tour (Hierholzer’s Algorithm)
    map<pair<int,int>,int> cnt;
    for(auto &e:multigraph){
        cnt[{e.first,e.second}]++;
        cnt[{e.second,e.first}]++;
    }
    vector<int> tour, st={0};
    while(!st.empty()){
        int v=st.back(), i;
        for(i=0;i<n;i++){
            if(cnt[{v,i}]>0){
                cnt[{v,i}]--; cnt[{i,v}]--;
                st.push_back(i);
                break;
            }
        }
        if(i==n){ tour.push_back(v); st.pop_back(); }
    }
    reverse(tour.begin(), tour.end());

    cout << "\nEuler Tour: ";
    for(int v:tour) cout << name[v] << " ";
    cout << "\n";

    // Step 6: Hamiltonian Cycle by shortcutting
    vector<int> visited(n,0), hcycle;
    for(int v:tour){
        if(!visited[v]){ hcycle.push_back(v); visited[v]=1; }
    }
    hcycle.push_back(hcycle[0]);

    cout << "\nHamiltonian Cycle: ";
    for(int v:hcycle) cout << name[v] << " ";
    cout << "\n";

    int cost=0;
    for(int i=0;i+1<hcycle.size();i++) cost+=dist[hcycle[i]][hcycle[i+1]];
    cout << "Tour cost = " << cost << "\n";

    return 0;
}
