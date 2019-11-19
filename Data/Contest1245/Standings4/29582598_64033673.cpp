#include <iostream>
#include <cmath>
#include <random>
#include <cassert>
#include <iomanip>
#include <set>
#include <map>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#define int long long
using namespace std;

const int MAXN = 2005;

int x[MAXN], y[MAXN], c[MAXN], k[MAXN];

struct Edge {
    int u, v;
    int w;
};

vector<Edge> E;

int dsu_p[MAXN];
int dsu_min[MAXN];
int dsu_sz[MAXN];
int dsu_min_v[MAXN];

int dsu_get(int u) {
    if (dsu_p[u] == u) return u;
    return dsu_p[u] = dsu_get(dsu_p[u]);
}

void dsu_merge(int u, int v) {
    u = dsu_get(u); v = dsu_get(v);
    if (dsu_sz[v] < dsu_sz[u]) swap(u, v);
    dsu_p[u] = v;
    dsu_sz[v] += dsu_sz[u];
    if (dsu_min[u] < dsu_min[v]) {
        dsu_min[v] = dsu_min[u];
        dsu_min_v[v] = dsu_min_v[u];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        ans += c[i];
    }
    for (int i = 0; i < n; i++) cin >> k[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            E.push_back({i, j, (k[i] + k[j])*(abs(x[i] - x[j]) + abs(y[i] - y[j]))});
        }
    }
    sort(begin(E), end(E), [](const Edge& a, const Edge& b) {return a.w < b.w;});
    for (int i = 0; i < n; i++) {
        dsu_p[i] = i;
        dsu_min[i] = c[i];
        dsu_min_v[i] = i;
    }
    vector<pair<int,int>> nedges;
    for (auto& e: E) {
        int u = dsu_get(e.u);
        int v = dsu_get(e.v);
        int w = e.w;
        if (u != v && dsu_min[u] + dsu_min[v] > w + min(dsu_min[u], dsu_min[v])) {
            ans -= max(dsu_min[u], dsu_min[v]);
            ans += w;
            dsu_merge(u, v);
            nedges.push_back({e.u, e.v});
        }
    }
    cout << ans << endl;
    set<int> comps;
    for (int i = 0; i < n; i++) comps.insert(dsu_min_v[dsu_get(i)]);
    cout << comps.size() << endl;
    for (int x: comps) cout << x + 1 << " ";
    cout << endl;
    cout << nedges.size() << endl;
    for (auto& p: nedges) cout << p.first + 1 << " " << p.second + 1 << endl;
}