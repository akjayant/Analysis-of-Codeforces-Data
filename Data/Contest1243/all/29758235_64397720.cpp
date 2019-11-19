#include<bits/stdc++.h>

//#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(v) (int) v.size()

using namespace std;

const int N = 1e5 + 5;

int n, m;
set<int> g[N];

main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[v].insert(u);
        g[u].insert(v);
    }
    set<pair<int, int>> Q;
    unordered_set<int> not0;
    for (int i = 0; i < n; ++i) {
        if (g[0].count(i)) {
            Q.insert({1, i});
            not0.insert(i);
        } else {
            Q.insert({0, i});
        }
    }
    int ans = 0;
    while (!Q.empty()) {
        ans += Q.begin()->X;
        int v = Q.begin()->Y;
        Q.erase(Q.begin());
        vector<int> del;
        for (int u : not0) {
            if (g[v].count(u)) {
                Q.insert({1, u});
            } else {
                Q.erase({1, u});
                Q.insert({0, u});
                del.pb(u);
            }
        }
        for (int u : del) {
            not0.erase(u);
        }
    }
    cout << ans << "\n";

    return 0;
}
