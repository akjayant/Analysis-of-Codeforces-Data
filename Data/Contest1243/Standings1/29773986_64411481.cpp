#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define pb push_back
#define ft first
#define sd second
#define inf (int)1e9

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

using namespace std;

vector <ll> g[200000];
ll p[200000];
ll sz[200000];
ll n;

void build() {
    for (ll i = 0; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
}

ll root(ll v) {
    if (v != p[v]) {
        p[v] = root(p[v]);
    }

    return p[v];
}

void uni(ll a, ll b) {
    a = root(a);
    b = root(b);

    if (a != b) {
        if (sz[a] > sz[b]) {
            p[b] = a;
            sz[a] += sz[b];
        }
        else {
            p[a] = b;
            sz[b] += sz[a];
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    vector <pair<ll,ll>> e;
    ll m;

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        ll a , b;
        cin >> a >> b;

        e.pb({a,b});
        g[a].pb(b);
        g[b].pb(a);
    }

    ll ans = 0;
    set <ll> pos;
    set <pair<ll,ll>> may;
    map <ll,ll> mp;

    pos.insert(1);
    for (ll i = 2; i <= n; i++) {
        may.insert({0, i});
        mp[i] = 0;
    }

    for (auto to:g[1]) {
        may.erase({0,to});
        may.insert({1,to});
        mp[to] = 1;
    }

    for (ll x = 2; x <= n; x++) {
        if (may.begin()->ft == pos.size()) {
            ans++;
        }

        ll ind = may.begin()->sd;
        may.erase(may.begin());
        pos.insert(ind);

        for (auto i: g[ind]) {
            if (pos.find(i) == pos.end()) {
                may.erase({mp[i],i});
                mp[i]++;
                may.insert({mp[i],i});
            }
        }
    }

    cout << ans;
    return 0;
}