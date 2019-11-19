#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

struct UF {
    vi par, size;
    UF(int n): par(n), size(n, 1) { iota(all(par), 0); }
    int find(int u) { return par[u] == u ? u : par[u] = find(par[u]); }
    bool connected(int u, int v) { return find(u) == find(v); }
    bool join(int u, int v) {
        if (connected(u, v)) return false;
        u = find(u), v = find(v);

        if (size[u] < size[v]) par[u] = v, size[v] += size[u];
        else par[v] = u, size[u] += size[v];
        return true;
    }
};

using Point = pii;
using Edge = pii;
using CostEdge = tuple<ll, int, int>;
using Comp = pair<int, ll>;

int dist(Point p, Point q) {
    return abs(p.fst - q.fst) + abs(p.snd - q.snd);
}

int main() {
	fastio;
	
    int n; cin >> n;
    vector<Point> pos(n); for (auto &[x, y] : pos) cin >> x >> y;
    vi power_cost(n); for (int &c : power_cost) cin >> c;
    vi wire_factor(n); for (int &w : wire_factor) cin >> w;

    vector<CostEdge> edges;
    forn(u, n) forsn(v, u + 1, n) {
        ll cost = (ll) dist(pos[u], pos[v]) * (wire_factor[u] + wire_factor[v]);
        edges.pb(cost, u, v);
    }
    sort(all(edges));

    UF uf(n);
    vector<Comp> comp_info(n);
    forn(u, n) comp_info[u] = {u, 0};

    vector<Edge> used_edges;

    for (auto [cost, u, v] : edges) if (!uf.connected(u, v)) {
        auto [station_u, connection_u] = comp_info[uf.find(u)];
        int power_u = power_cost[station_u];
        auto [station_v, connection_v] = comp_info[uf.find(v)];
        int power_v = power_cost[station_v];

        if (cost + min(power_u, power_v) < power_u + power_v) {
            uf.join(u, v);
            
            int w = uf.find(u);
            comp_info[w] = {power_u < power_v ? station_u : station_v, connection_u + connection_v + cost};

            used_edges.pb(u, v);
        }
    }

    ll total_cost = 0;
    vi built_stations;
    forn(u, n) if (uf.find(u) == u) {
        auto [station, connection] = comp_info[u];

        total_cost += connection;

        built_stations.pb(station);
        total_cost += power_cost[station];
    }

    cout << total_cost << endl;
    int k = si(built_stations);
    cout << k << endl;
    forn(i, k) cout << built_stations[i] + 1 << " \n"[i == k - 1];
    cout << si(used_edges) << endl;
    for (auto [u, v] : used_edges) cout << u + 1 << ' ' << v + 1 << endl;
	
	return 0;
}
