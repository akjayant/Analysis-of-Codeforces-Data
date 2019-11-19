#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define mp make_pair
 
const int N = 2e5 + 5;
const int mod = 1e9+7;
const ll INF = (ll)4e18 + 5;

inline int mul(int a, int b){
    return ((ll)a * b) % mod;
}

inline int add(int a, int b){
    int ans = a + b;
    if(ans >= mod) ans -= mod;
    return ans; 
}

// credits : codeforces :https://codeforces.com/blog/entry/54396
bool isprime(ll n){
    if(n<2) return false;
    for(ll i=2;i*i*i<=n;++i) if(n%i==0) return false;
    for(int it=0;it<1e2;++it){
        ll i = rand()%(n-1)+1;
        if(__gcd(i,n)!=1) return false;
        // if(mpow(i,n-1,n)!=1) return false;
    }
    return true;
}

ll fast_pow(ll a, ll b){
    ll ans = 1;
    a %= mod;
    while(b){
        if(b&1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

struct seg_tree{
    vector<ll> seg;
    vector<ll> lzy;
    int n;

    seg_tree(int x) : n(x){
        seg.resize(4*n+5);
        lzy.resize(4*n+5);
    } 

    void update_lzy(int l, int r, int i){
        if(!lzy[i]) return;
        seg[i] += lzy[i];
        if(l != r) lzy[i*2+1] += lzy[i], lzy[i*2+2] += lzy[i];
        lzy[i] = 0;
    }

    void update(int x, int y, ll val, int l = 0, int r = -1, int i = 0){
        if(r == -1) r += n;
        update_lzy(l, r, i);
        if(r < x || l > y) return; 
        if(l >= x && r <= y){
            lzy[i] += val;
            return update_lzy(l, r, i);
        }
        int m = (l+r) >> 1;
        update(x, y, val, l, m, i*2+1);
        update(x, y, val, m+1, r, i*2+2);
        seg[i] = min(seg[i*2+1], seg[i*2+2]);
    }

    ll query(int x, int y, int l = 0, int r = -1, int i = 0){
        if(r == -1) r += n;
        update_lzy(l, r, i);
        if(r < x || l > y) return INF;
        if(l >= x && r <= y) return seg[i];
        int m = (l+r) >> 1;
        ll ans = min(query(x, y, l, m, i*2+1), query(x, y, m+1, r, i*2+2));
        return ans;
    }
};

vector<int> g[N];

struct DSU{
    vector<int> sz, p;

    DSU(int n){
        sz.resize(n+1, 1);
        p.resize(n+1, 0);
        for(int j = 1; j <= n; j++) p[j] = j;
    }

    int par(int x){
        return (p[x] == x)? x : p[x] = par(p[x]);
    }

    void merge(int u, int v){
        // cout << "merge: " << u << " " << v << endl;
        u = par(u);
        v = par(v);
        if(sz[u] > sz[v]) swap(sz[u], sz[v]);
        sz[v] += sz[u];
        p[u] = v;
    }
};

void explore(int v, DSU& dsu, const int n){
    vector<int> present(n+1, 0);
    for(auto i : g[v]) present[i] = 1;
    for(int j = 1; j <= n; j++)
        if(!present[j]) dsu.merge(v, j);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> in(N, 0);
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        in[u] ++;
        in[v] ++;
        g[u].pb(v);
        g[v].pb(u);
    }
    int mn_ind = 1;
    for(int j = 1; j <= n; j++)
        if(in[mn_ind] > in[j]) mn_ind = j;

    // root is 'j'
    DSU dsu(n);
    // cout << mn_ind << endl;
    explore(mn_ind, dsu, n);
    vector<int> present(n+1, 0);
    for(auto i : g[mn_ind]) present[i] = 1;
    for(int j = 1; j <= n; j++)
        if(present[j]) explore(j, dsu, n);

    int remain = 0;
    for(int j = 1; j <= n; j++)
        if(dsu.par(j) == j){ 
            // cout << j << endl;
            remain ++;
        }
    cout << remain-1 << endl;
    return 0;
}
