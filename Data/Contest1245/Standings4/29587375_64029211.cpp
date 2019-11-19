//                                      KiSmAt
#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const int N = 2 * 1e3 + 10;

ll res;
ll pw[N];
ll a[N], c[N], par[N];

ll dist;

set<ll> g[N], st;
vector<pair<ll, ll> > v, e;
vector<pair<ll, pair<ll, ll> > > vv, edge;

ll root(ll x){
    while(x != par[x]){
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

void join(ll x, ll y){
    par[root(x)] = par[root(y)];
}

ll get(ll node, ll p){
    ll val = node;
    for(auto i: g[node]){
        if(i == p)  continue;
        ll x = get(i, node);
        if(c[x] < c[val])   val = x;    
    }
    return val;
}

void solve(){
    ll n;
    cin >> n;
    v.resize(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> v[i].first >> v[i].second;
        par[i] = i;
    }
    ll mi = inf, gg;
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
        if(mi > c[i]){
            mi = c[i];
            gg = i;
        }
    }
    for(int i = 1; i <= n; ++i){
        cin >> pw[i];
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j)  continue;
            dist = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            vv.push_back({dist * (pw[i] + pw[j]), {i, j}});
        }
    }
    sort(vv.begin(), vv.end());
    for(auto i: vv){
        if(root(i.second.first) == root(i.second.second))   continue;
        edge.push_back({i.first, {i.second.first, i.second.second}});
        g[i.second.first].insert(i.second.second);
        g[i.second.second].insert(i.second.first);
        join(i.second.first, i.second.second);
        res += i.first;
    }
    res += c[gg];
    st.insert(gg);
    sort(edge.rbegin(), edge.rend());
    for(auto i: edge){
        ll gg = get(i.second.first, i.second.second);
        ll wp = get(i.second.second, i.second.first);
        ll ans = 0;
        if(st.find(gg) == st.end()) ans += c[gg];
        if(st.find(wp) == st.end())    ans += c[wp];
        if(ans < i.first){
            g[i.second.first].erase(i.second.second);
            g[i.second.second].erase(i.second.first);
            st.insert(gg);
            st.insert(wp);
            res -= i.first;
            res += ans;
        }
        else    e.push_back({i.second.first, i.second.second});
    }
    cout << res << "\n" << st.size() << "\n";
    for(auto i: st) cout << i << " ";
    cout << "\n" << e.size() << "\n";
    for(auto i: e)  cout << i.first << " " << i.second << "\n";
}
 
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
// nEro