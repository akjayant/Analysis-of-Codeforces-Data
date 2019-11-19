#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

const int N = 2000;

int n, dp[N], x[N], y[N], c[N], k[N], pr[N], p[N], sz[N], res[N];

pair<int, int> mn[N];

int find(int i) {
    if (p[i] == i) return i;
    return p[i] = find(p[i]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (sz[a] > sz[b]) swap(a, b);
    sz[b] += sz[a];
    mn[b] = min(mn[a], mn[b]);
    p[a] = b;
    res[b] += res[a];
}

void lol_anton() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++) cin >> c[i], mn[i] = {c[i], i}, sz[i] = 1, p[i] = i;
    for (int i = 0; i < n; i++) cin >> k[i];
    vector<pair<int, int>> edges;
    set<int> center;
    vector<pair<int, int>> mega_sort;
    int ans = 0;
    for (int f = 0; f < n; f++) {
        dp[f] = c[f];
        ans += c[f];
        for (int s = f + 1; s < n; s++) mega_sort.push_back({f, s});
    }
    auto calc = [&](pair<int, int> &a) {
        auto [i1, j1] = a;
        return (k[i1] + k[j1]) * (abs(x[i1] - x[j1]) + abs(y[i1] - y[j1]));
    };
    sort(all(mega_sort), [&](pair<int, int> &a, pair<int, int> &b){
        return calc(a) < calc(b);
    });
    for (int f = 0; f < mega_sort.size(); f++) {
        auto [i, j] = mega_sort[f];
        int v = calc(mega_sort[f]);
        int I = find(i), J = find(j);
        if (I == J) continue;
        if (mn[I] > mn[J]) swap(i, j), swap(I, J);
        if (mn[J].first > v) {
            ans -= mn[J].first;
            ans += v;
            merge(I, J);
            edges.push_back({i, j});
        }
    }
    for (int i = 0; i < n; i++) center.insert(mn[find(i)].second);
    cout << ans << endl << center.size() << endl;
    for (auto x : center) cout << x + 1 << ' ';
    cout << endl << edges.size() << endl;
    for (auto [a, b] : edges) cout << a + 1 << ' ' << b + 1 << '\n';
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    lol_anton();
}