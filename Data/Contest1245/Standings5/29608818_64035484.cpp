// C++ program for Kruskal's algorithm to find Minimum 
// Spanning Tree of a given connected, undirected and 
// weighted graph 
#include<bits/stdc++.h> 
#include <algorithm>
using namespace std; 
# define int long long

// Creating shortcut for an integer pair 
typedef pair<int, int> iPair; 

// Structure to represent a graph 
struct Graph 
{ 
    int V, E; 
    vector< pair<int, iPair> > edges; 

    // Constructor 
    Graph(int V, int E) 
    { 
        this->V = V; 
        this->E = E; 
    } 

    // Utility function to add an edge 
    void addEdge(int u, int v, int w) 
    { 
        edges.push_back({w, {u, v}}); 
    } 

    int kruskalMST(vector<int> &v,vector<pair<int,int>> &connections); 
}; 

struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 

    DisjointSets(int n) 
    { 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 

        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 

            parent[i] = i; 
        } 
    } 


    int find(int u) 
    { 
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 

    // Union by rank 
    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 

        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else // If rnk[x] <= rnk[y] 
            parent[x] = y; 

        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 


int Graph::kruskalMST(vector<int> &powerstations, vector<pair<int,int>> &connections) 
{ 
    int mst_wt = 0; 


    sort(edges.begin(), edges.end()); 

    DisjointSets ds(V); 

    vector< pair<int, iPair> >::iterator it; 
    for (it=edges.begin(); it!=edges.end(); it++) 
    { 
        int u = it->second.first; 
        int v = it->second.second; 

        int set_u = ds.find(u); 
        int set_v = ds.find(v); 

        if (set_u != set_v) 
        { 
            if(u==0) powerstations.push_back(v);
            else if(v==0) powerstations.push_back(u);
            else connections.push_back({u,v});

            mst_wt += it->first; 
            ds.merge(set_u, set_v); 
        } 
    } 

    return mst_wt; 
} 

signed main() 
{ 
    int c; cin>>c;
    vector<pair<int,int>> v(c);
    for (int i = 0; i < c; ++i)
    {
        int a,b; cin>>a>>b;
        v[i] = {a,b};
    }
    int V = c+1, E = c*c; 
    Graph g(V, E); 
    int n=c;
    vector<int> ci(n+1);
    vector<int> ki(n+1);
    for (int i = 0; i < n; ++i)
    {
        cin>>ci[i+1];
    }
    for (int i = 0; i < n; ++i)
    {
        cin>>ki[i+1];
    }
    for (int i = 1; i <= n; ++i)
    {
        g.addEdge(0,i,ci[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if(i!=j) g.addEdge(i,j,(ki[i]+ki[j])*(abs(v[i-1].first-v[j-1].first) + abs(v[i-1].second-v[j-1].second)));
        }
    }

    vector<int> powerstations; 
    vector<pair<int,int>> connections;
    int mst_wt = g.kruskalMST(powerstations, connections);
    cout<<mst_wt<<endl;
    cout<<powerstations.size()<<endl;

    for (int i = 0; i < powerstations.size(); ++i)
    {
     cout<<powerstations[i]<<" ";
    } cout<<endl;
    cout<<connections.size()<<endl;

    for (int i = 0; i < connections.size(); ++i)
    {
        cout<<connections[i].first<<" "<<connections[i].second<<endl;
    }

    return 0; 
} 
