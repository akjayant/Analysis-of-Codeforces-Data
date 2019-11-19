#include <iostream>
#include <vector>
#include <functional>
#include <set>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    const int color_cnt = 3;
    vector<int> cost[color_cnt] = { vector<int>(n), vector<int>(n), vector<int>(n) };
    for (auto &i : cost) {
        for (auto &val : i)
            cin >> val;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() > 2) {
            cout << "-1\n";
            return;
        } else if (g[i].size() == 1) {
            root = i;
        }
    }
    vector<int> path;
    path.reserve(n);
    function<void(int, int)> dfs = [&] (int v, int anc) {
        path.push_back(v);
        for (auto &u : g[v]) {
            if (u == anc)
                continue;
            dfs(u, v);
        }
    };
    dfs(root, -1);
    int perm[] = { 0, 1, 2 };
    int64_t ans = 0;
    vector<int> color;
    int flag = 0;
    do {
        int cur = 0;
        int64_t tmp = 0;
        vector<int> tmp_color(n);
        for (auto &u : path) {
            tmp_color[u] = perm[cur];
            tmp += cost[perm[cur]][u];
            if (cur + 1 == color_cnt)
                cur = 0;
            else
                ++cur;
        }
        if (!flag || tmp < ans) {
            flag = 1;
            ans = tmp;
            color = move(tmp_color);
        }
    } while (next_permutation(perm, perm + color_cnt));
    cout << ans << '\n';
    for (auto &c : color)
        cout << c + 1 << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}