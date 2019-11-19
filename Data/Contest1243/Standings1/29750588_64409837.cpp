#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define int long long

const int INF = 1e18;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    set<pair<int, int>> e;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        e.insert({x - 1, y - 1});
        e.insert({y - 1, x - 1});
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
    int res = 0;
    vector<int> cnt(n);
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        s.insert({0, i});
    }
    vector<int> used(n);
    for (int i = 0; i < n; i++) {
        auto v = *s.begin();
        s.erase(s.begin());
        used[v.second] = 1;
        if (i == cnt[v.second]) {
            res++;
        }
        for (int to : g[v.second]) {
            if (!used[to]) {
                s.erase({cnt[to], to});
                cnt[to]++;
                s.insert({cnt[to], to});
            }
        }
        //for (auto k : s) cout << k.first << ' '
    }
    cout << res - 1;
}

int32_t main() {
#ifdef local
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int q = 1;
    while (q--) solve();
    return 0;
}