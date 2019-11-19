#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
const ll MOD = 1e9+7;

#include<bits/stdc++.h> 
using namespace std; 
  
// Creating shortcut for an lleger pair 
typedef  pair<ll, ll> iPair; 
  
// Structure to represent a graph 
struct Graph 
{ 
    ll V, E; 
    vector< pair<ll, iPair> > edges; 
  
    // Constructor 
    Graph(ll V, ll E) 
    { 
        this->V = V; 
        this->E = E; 
    } 
  
    // Utility function to add an edge 
    void addEdge(ll u, ll v, ll w) 
    { 
        edges.push_back({w, {u, v}}); 
    } 
  
    // Function to find MST using Kruskal's 
    // MST algorithm 
    ll kruskalMST(); 
}; 
  
// To represent Disjoll Sets 
struct DisjollSets 
{ 
    ll *parent, *rnk; 
    ll n; 
  
    // Constructor. 
    DisjollSets(ll n) 
    { 
        // Allocate memory 
        this->n = n; 
        parent = new ll[n+1]; 
        rnk = new ll[n+1]; 
  
        // Initially, all vertices are in 
        // different sets and have rank 0. 
        for (ll i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
  
            //every element is parent of itself 
            parent[i] = i; 
        } 
    } 
  
    // Find the parent of a node 'u' 
    // Path Compression 
    ll find(ll u) 
    { 
        /* Make the parent of the nodes in the path 
           from u--> parent[u] poll to parent[u] */
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  
    // Union by rank 
    void merge(ll x, ll y) 
    { 
        x = find(x), y = find(y); 
  
        /* Make tree with smaller height 
           a subtree of the other tree  */
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else // If rnk[x] <= rnk[y] 
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 
  
 /* Functions returns weight of the MST*/ 
    vector<pair<ll,ll>> ans;
  
ll Graph::kruskalMST() 
{ 
    ll mst_wt = 0; // Initialize result 
    ans.clear();
    // Sort edges in increasing order on basis of cost 
    sort(edges.begin(), edges.end()); 
  
    // Create disjoll sets 
    DisjollSets ds(V); 
    // Iterate through all sorted edges 
    vector< pair<ll, iPair> >::iterator it; 
    for (it=edges.begin(); it!=edges.end(); it++) 
    { 
        ll u = it->second.first; 
        ll v = it->second.second; 
  
        ll set_u = ds.find(u); 
        ll set_v = ds.find(v); 

        if (set_u != set_v) 
        { 
            // cout << u << " - " << v << endl; 
            ans.push_back({u,v});
            mst_wt += it->first; 
  
            ds.merge(set_u, set_v); 
        } 
    } 
  
    return mst_wt; 
} 


int main(){
    //fastio;
    ll n;
    cin>>n;
    vector<pair<ll,ll>> a(n);
    Graph g(n+1, n*n);
    for(ll i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    vector<ll> costs(n), k(n);
    // vector<edge> alledge;
    for(ll i=0;i<n;i++){
        cin>>costs[i];
        g.addEdge(0,i+1,costs[i]);
    }
    for(ll i=0;i<n;i++){
        cin>>k[i];
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i == j) continue;
            ll cost = (k[i]+k[j])*(abs(a[i].first-a[j].first) + abs(a[i].second-a[j].second));
            g.addEdge(i+1, j+1, cost);
        }
    }
    ll app = g.kruskalMST();
    int cnt=0, cnt2=0;
    for(int i=0;i<ans.size();i++){
        // cout << ans[i].first << " " << ans[i].second << endl; 
        if(ans[i].first == 0 || ans[i].second==0){
            cnt++;
        }
        else{
            cnt2++;
        }
    }

    cout << app << endl;
    cout << cnt << endl;
    for(int i=0;i<ans.size();i++){
        // cout << ans[i].first << " " << ans[i].second << endl; 
        if(ans[i].first == 0 || ans[i].second==0){
            cout << max(ans[i].first, ans[i].second) << " ";
        }
    }
    cout << endl;
    cout << cnt2 << endl;
    for(int i=0;i<ans.size();i++){
        // cout << ans[i].first << " " << ans[i].second << endl; 
        if(ans[i].first == 0 || ans[i].second==0){
        }
        else{
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}