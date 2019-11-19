#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
vector<vector<int>> edges;
vector<vector<int>> price;
vector<int> color;

ll dfs(int u, int c1, int c2) {
    color[u] = 3 - c1 - c2;
    ll sum = price[u][color[u]];
    for (int v : edges[u]) {
        if (color[v] == -1) {
            sum += dfs(v, color[u], c1);
        }
    }
    return sum;
}

void solve() {
    cin >> n;
    edges.resize(n);
    price.resize(n, vector<int>(3, 0));
    color.resize(n, -1);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++)
            cin >> price[j][i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
        if (edges[i].size() > 2) {
            cout << -1;
            return;
        }

    ll ans = 2e18;
    vector<int> ans_vec;
    for (int c1 = 0; c1 < 3; c1++)
        for (int c2 = 0; c2 < 3; c2++) {
            if (c1 == c2)
                continue;
            fill(color.begin(), color.end(), -1);
            color[0] = c1;
            color[edges[0][0]] = c2;
            int v = edges[0][0];
            ll sum = price[0][c1] + price[v][c2];
            for (int i = 1; i < edges[0].size(); i++) {
                sum += dfs(edges[0][i], c1, c2);
            }
            for (int i = 0; i < edges[v].size(); i++) {
                if (edges[v][i] != 0)
                    sum += dfs(edges[v][i], c2, c1);
            }
            if (sum < ans) {
                ans = sum;
                ans_vec = color;
            }
        }

    cout << ans << "\n";
    for (int val : ans_vec) {
        cout << val + 1 << " ";
    }

}

int main() {
	//~ freopen(".in", "r", stdin);
	//~ freopen(".out", "w", stdout);
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
    solve();
    return 0;
}
