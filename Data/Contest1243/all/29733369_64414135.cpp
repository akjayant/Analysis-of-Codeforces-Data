//#pragma comment(linker,"/STACK:36777216")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define itoc(c) (char)((int)'0' + c)
#define ctoi(c) (int)(c - '0')
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define emb emplace_back
#define pb push_back

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

const int oo = 1e9;
const int MOD = 1e9+7;
const int N = 1e5+5;

int n, m, par[N];
queue<int> q;
set<int> adj[N], st;
vector<pii> edges;

int root(int v) {
    return (par[v]<0) ? v : (par[v]=root(par[v]));
}

void join(int x, int y) {
    if ((x=root(x))==(y=root(y))) return;
    if (par[x]>par[y]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}

int calc(int start) {
    st.erase(start);
    int res=0;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        par[u]=start; ++res;
        int last=0;
        for (int v: adj[u]) {
            auto it1=st.upper_bound(last);
            auto it2=st.lower_bound(v);
            --it2;
            if (*it1<=*it2) {
                ++it2;
                vector<int> tmp;
                while (it1 != it2) {
                    q.push(*it1);
                    tmp.push_back(*it1);
                    ++it1;
                }
                for (int x: tmp) st.erase(x);
            }
            last=v;
        }
    }
    return -res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while (m--) {
        int u,v; cin>>u>>v;
        adj[u].emplace(v);
        adj[v].emplace(u);
        edges.emb(u,v);
    }
    for (int i=1; i<=n; ++i) {
        st.emplace(i);
        adj[i].emplace(n+1);
    }
    st.emplace(0);

    for (int i=1; i<=n; ++i) {
        if (st.find(i)!=st.end()) {
            q.push(i);
            par[i]=calc(i);
        }
    }

    int res=0;
    for (auto e: edges) {
        if (root(e.ff)==root(e.ss)) continue;
        join(e.ff, e.ss);
        ++res;
    }
    cout<<res;
    return 0;
}