#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // include pb_ds

using namespace std;
using namespace __gnu_pbds; // namespace for pb_ds

/* short forms */
#define Accelerate                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define cld(x, y) (((x) / (y)) + ((x) % (y) != 0)) //integer ceil division
#define tc(tt) \
    int tt;    \
    cin >> tt; \
    for (int _tt = 0; _tt < tt; _tt++) // testcase
#define all(cont) (cont).begin(), (cont).end()
#define sz(cont) (int)(cont).size()
#define endl '\n'
#define cout_p(x, p) cout << fixed << setprecision((p)) << x << endl //print with precision
#define dbg(x) cerr << #x << "is" << (x) << endl
#define leadzero(a) __builtin_clz(a)      // count leading zeroes
#define trailzero(a) __builtin_ctz(a)     // count trailing zeroes
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)

/* constants */
const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;

/* typedefs */
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;
typedef priority_queue<int, vector<int>> max_heap;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
    indexed_set; // integer set with indexing / pb_ds

vector<vector<int> > adj;
vector<int> path;
vector<bool> vis;
void dfs(int s) {
    vis[s] = 1;
    path.pb(s);
    // cout << path[path.size()-1] << endl;
    for(auto v:adj[s]) {
        if(!vis[v])dfs(v);
    }
}
/* main program */
int main()
{
    Accelerate;
    int n;
    cin >> n;
    ll int c[n+1][3];
    for(int i=0;i<3;i++) {
        for(int j=1;j<=n;j++) cin >> c[j][i];
    }
    adj.resize(n+1);
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int st = -1;
    bool flag = 1;
    for(int i=1;i<=n;i++) {
        if(adj[i].size()==1) st=i;
        if(adj[i].size()>2) flag = 0;
    }
    if(!flag) {
        cout << -1 << endl;
        return 0;
    }
    // cout << st << endl;
    vis.resize(n+1,0);
    dfs(st);
    // for(int i=0;i<n;i++) cout << path[i] << " ";
    // cout << endl;
    
    ll int ans = LLONG_MAX;
    vector<tuple<int,int,int> > comb ;
    comb.pb(mt(0,1,2));
    comb.pb(mt(0,2,1));
    comb.pb(mt(1,0,2));
    comb.pb(mt(1,2,0));
    comb.pb(mt(2,0,1));
    comb.pb(mt(2,1,0));
    int mini = -1;
    for(int cnum=0;cnum<6;cnum++) {
        int col[3];
        tie(col[0],col[1],col[2]) = comb[cnum]; 
        ll int cost = 0;
        for(int i=0;i<n;i++) {
            cost += c[path[i]][col[i%3]];
        }
        if(cost <= ans) {
            ans = cost;
            mini = cnum;
        }
        ans = min(ans,cost);
    }
    cout << ans << endl;
    
    int col[3];
    tie(col[0],col[1],col[2]) = comb[mini]; 
    int res[n+1];
    
    for(int i=0;i<n;i++) {
        res[path[i]] = col[i%3]+1;
    }
    for(int i=1;i<=n;i++) cout << res[i] << " ";

    cout << endl;

    return 0;
}
