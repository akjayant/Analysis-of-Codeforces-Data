//#pragma comment(linker,"/STACK:36777216")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define emb emplace_back
#define pb push_back
using ll = long long;
using ii = pair<int, int>;
const int N = 2005;

int n, par[N];
ll x[N], y[N], c[N], k[N], res;
vector<int> station;
vector<ii> connection;
vector<pair<ll,ii>> edges;

int root(int v) {
    return (par[v]<0) ? v : (par[v]=root(par[v]));
}

void join(int x, int y) {
    if ((x=root(x))==(y=root(y))) return;
    if (par[x]>par[y]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; ++i) cin>>x[i]>>y[i];
    for (int i=1; i<=n; ++i) cin>>c[i];
    for (int i=1; i<=n; ++i) cin>>k[i], par[i]=-1;

    for (int i=1; i<=n; ++i) {
        edges.push_back({c[i], {0,i}});
        for (int j=i+1; j<=n; ++j) {
            ll cost=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
            edges.push_back({cost, {i,j}});
        }
    }
    par[0]=-1;
    sort(edges.begin(), edges.end());
    for (auto e: edges) {
        int u=e.ss.ff, v=e.ss.ss;
        if (root(u)==root(v)) continue;
        res+=e.ff;
        join(u,v);
        if (u==0) station.pb(v);
        else connection.emb(u,v);
    }
    cout<<res<<"\n";
    cout<<station.size()<<"\n";
    for (int x: station) cout<<x<<" ";
    cout<<"\n";
    cout<<connection.size()<<"\n";
    for (ii x: connection) cout<<x.ff<<" "<<x.ss<<"\n";
    return 0;
}