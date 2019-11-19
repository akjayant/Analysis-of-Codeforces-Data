#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef vector<ppi> vppi;
typedef map<int,int> mii;
typedef map<int,vi> mvi;
typedef map<pii,int> mpi;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) (v).begin(),(v).end()
#define For(i,n) for(int i=0;i<(int)n;i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(w,x,y,z) cout<<(w)<<" "<<(x)<<" "<<(y)<<" "<<(z)<<endl
const int mod=1e9+7;
#define ZERO(a) memset(a,0,sizeof(a))
#define Acc(i,n,a) for(int i=0;i<(int)n;i++) cin>>a[i]
#define Acc2(i,n,a,b) for(int i=0;i<(int)n;i++) cin>>a[i]>>b[i]
#define Debug(i,n,a) For(i,n) cout<<a[i]<<" ";cout<<endl;


ll GCD( ll x, ll y) { if(y==0) return x; return GCD(y,x%y);}
ll LCM( ll x, ll y) { return (x*y)/GCD(x,y);}
ll MPOW( ll a, ll b, ll m) { if(b==0) return 1; ll x=MPOW(a,b/2,m); x=(x*x)%m; if(b%2==1) x=(x*a)%m; return x;}
ll MINV( ll a, ll m) { return MPOW(a,m-2,m);}
ll MFACT( ll n, ll m){ if(m<=n) return 0; else if(n==0) return 1; else return ((MFACT(n-1,m)*n)%m);}
inline ll max( ll a, ll b) { return (a>b)?a:b;}
inline ll min( ll a, ll b){ return (a<b)?a:b;}
inline void swap( ll &a, ll &b){ ll temp=a; a=b; b=temp; return;}
inline ll max3( ll a, ll b, ll c){ return max(a,max(b,c));}
inline ll min3( ll a, ll b, ll c){ return min(a,min(b,c));}
vpi allp;
typedef  pair<int, int> iPair; 
  
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
  
    // Function to find MST using Kruskal's 
    // MST algorithm 
    int kruskalMST(); 
}; 
  
// To represent Disjoint Sets 
struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 
  
    // Constructor. 
    DisjointSets(int n) 
    { 
        // Allocate memory 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
  
        // Initially, all vertices are in 
        // different sets and have rank 0. 
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
  
            //every element is parent of itself 
            parent[i] = i; 
        } 
    } 
  
    // Find the parent of a node 'u' 
    // Path Compression 
    int find(int u) 
    { 
        /* Make the parent of the nodes in the path 
           from u--> parent[u] point to parent[u] */
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  
    // Union by rank 
    void merge(int x, int y) 
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
  
int Graph::kruskalMST() 
{ 
    int mst_wt = 0; // Initialize result 
  
    // Sort edges in increasing order on basis of cost 
    sort(edges.begin(), edges.end()); 
  
    // Create disjoint sets 
    DisjointSets ds(V); 
  
    // Iterate through all sorted edges 
    vector< pair<int, iPair> >::iterator it; 
    for (it=edges.begin(); it!=edges.end(); it++) 
    { 
        int u = it->second.first; 
        int v = it->second.second; 
  
        int set_u = ds.find(u); 
        int set_v = ds.find(v); 
  
        // Check if the selected edge is creating 
        // a cycle or not (Cycle is created if u 
        // and v belong to same set) 
        if (set_u != set_v) 
        { 
            // Current edge will be in the MST 
            // so print it 
            
            allp.push_back(mp(max(u,v), min(u,v)));
  
            // Update MST weight 
            mst_wt += it->first; 
  
            // Merge two sets 
            ds.merge(set_u, set_v); 
        } 
    } 
  
    return mst_wt; 
} 
main()
{
  fio;
  int T;
  //cin>>T;
  T=1;
  while(T--)
  {
    cout<<fixed;
    cout<<setprecision(0);
    int n,m;
    cin>>n;
    int a[n], b[n];
    Acc2(i,n,a,b);

    int c[n], k[n];
    Acc(i,n,c);
    Acc(i,n,k);

    int V=2*n;
    int E=n*n;
    Graph g(V,E);
    For(i,n){
      for(int j=i+1; j<n; j++){
        g.addEdge(i,j,(k[i]+k[j])*(abs(a[i]-a[j])+abs(b[i]-b[j])));
        g.addEdge(n+i, n+j, 0);
      }
    }
    For(i,n) g.addEdge(i,n+i, c[i]);
    cout<<g.kruskalMST()<<endl;
    vi alones;
    vpi doubles;
    For(i,allp.size()){
      if(allp[i].F>=n && allp[i].S<n)
        alones.pb(allp[i].S);
      else if(allp[i].F<n && allp[i].S<n)
        doubles.pb(allp[i]);
    }
    cout<<alones.size()<<endl;
    For(i,alones.size())
    cout<<alones[i]+1<<" ";
    cout<<endl;
    cout<<doubles.size()<<endl;
    For(i,doubles.size())
    cout<<doubles[i].F+1<<" "<<doubles[i].S+1<<endl;

  }
    return 0;
}
