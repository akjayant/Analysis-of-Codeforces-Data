#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

#define X first
#define Y second
#define A(x) get<0>(x)
#define B(x) get<1>(x)
#define C(x) get<2>(x)
#define D(x) get<3>(x)

mt19937 gen(228);

#ifdef DEBUG
#define dbg(x) cout << "[dbg " << __LINE__ << "] " << x << endl
#else
#define dbg(x) ((void)0)
#endif

constexpr ll MOD = 1'000'000'007;

constexpr int N = 2005;

pii cities [N];
vector<pair<ll, int>> g [2*N];
int c [N];
int k [N];

bool ok [N];

template <size_t MAXN>
struct dsu {
    int parent[MAXN], size[MAXN];
    bool has_station[MAXN];

    dsu() {
        for (int i = 0; i < MAXN; i++) {
            init(i);
        }
    }

    void init(int i) {
        parent[i] = i;
        size[i] = 1;
    }

    int get_parent(int i) {
        if (i == parent[i]) return i;
        parent[i] = get_parent(parent[i]);
        return parent[i];
    }

    int get_size(int i) {
        return size[get_parent(i)];
    }

    bool station(int i) {
        return has_station[get_parent(i)];
    }

    bool set_station(int i, bool st) {
        has_station[get_parent(i)] = st;
    }

    void set_union(int i, int j) {
        i = get_parent(i);
        j = get_parent(j);

        if (i != j) {
            if (size[i] < size[j])
                swap(i, j);

            parent[j] = i;
            size[i] += size[j];
            has_station[i] = has_station[i] || has_station[j];
        }
    }
};

dsu<N> dd;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cities[i].X >> cities[i].Y;
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    vector<pair<ll, tuple<int, int, int>>> e;

    for (int i = 0; i < n; i++) {
        e.pb({c[i], {0, i, i}});
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ll cost = (abs(cities[i].X - cities[j].X) + abs(cities[i].Y - cities[j].Y)) * 1LL * (k[i] + k[j]);
            e.pb({cost, {1, i, j}});
            //e.pb({cost, {1, j, i}});
        }
    }

    sort(all(e));

    vector<int> stations;
    vector<pii> edges;
    ll total = 0;

    for (auto [cost, tt] : e) {
        auto [type, u, v] = tt;

        if (type == 0) {
            if (!dd.station(u)) {
                stations.pb(u);
                dd.set_station(u, true);
                total += cost;
            }
        } else {
            if ((!dd.station(u) || !dd.station(v)) && dd.get_parent(u) != dd.get_parent(v)) {
                dd.set_union(u, v);
                total += cost;
                edges.pb({u, v});
            }
        }

        dbg(type << " " << cost << " " << total);
    }

    cout << total << "\n";

    cout << stations.size() << "\n";
    for (auto s : stations) {
        cout << s+1 << " ";
    }

    cout << "\n";

    cout << edges.size() << "\n";
    for (auto [u, v] : edges) {
        cout << u+1 << " " << v+1 << "\n";
    }

    return 0;
}