#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;

struct edge {
    ll u;
    ll v;
    ll cost;
};

vector<int> build;
vector<pair<int, int>> bridge;
vector<edge> es;
ll V, E;

// Union Find
struct UnionFind {
    vector<ll> data;
    UnionFind(ll size) : data(size, -1) { }
    bool unionSet(ll x, ll y) {
        x = root(x);
        y = root(y);

        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool findSet(ll x, ll y) { return root(x) == root(y); }
    ll root(ll x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    ll size(ll x) { return -data[root(x)]; }
};

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

ll kruskal(int n) {
    sort(es.begin(), es.end(), comp);
    UnionFind uf = UnionFind(V);
    ll res = 0;

    for (ll i=0; i<E; ++i) {
        edge e = es[i];
        if (!uf.findSet(e.u, e.v)) {
            uf.unionSet(e.u, e.v);
            res += e.cost;
            if(e.u == n){
                build.push_back(e.v);
            }
            else{
                bridge.push_back(pair<int, int>{e.v, e.u});
            }
        }
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<pair<ll, ll>> xy;
    for(ll i=0; i<n; i++){
        ll x, y; cin >> x >> y;
        xy.push_back(pair<ll, ll>{x, y});
    }
    vector<ll> cs;
    for(ll i=0; i<n; i++){
        ll c; cin >> c;
        cs.push_back(c);
    }
    vector<ll> ks;
    for(ll i=0; i<n; i++){
        ll k; cin >> k;
        ks.push_back(k);
    }
    for(ll i=0; i<n; i++){
        edge e;
        e.cost = cs[i];
        e.u = n;
        e.v = i;
        es.push_back(e);
        E++;
        ll xi = xy[i].first;
        ll yi = xy[i].second;
        ll ki = ks[i];
        for(ll j=i+1; j<n; j++){
            ll xj = xy[j].first;
            ll yj = xy[j].second;
            ll cost = (abs(xi - xj) + abs(yi - yj)) * (ks[j] + ki);
            edge e;
            e.cost = cost;
            e.u = i;
            e.v = j;
            es.push_back(e);
            E++;
        }
    }
    V = n + 1;
    ll ans = kruskal(n);
    cout << ans << endl;
    cout << (int)build.size() << endl;
    for(auto& v:build){
        cout << v + 1 << " ";
    }
    cout << endl;
    cout << (int)bridge.size() << endl;
    if((int)bridge.size() > 0){
        for(auto& v:bridge){
            cout << v.first + 1 << " " << v.second + 1 << endl;
        }
    }
    return 0;
}