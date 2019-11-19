#include <bits/stdc++.h>

#define int long long
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
int c[3][N];
vector<int> g[N];
vector<int> cur;
int dp[N][4][4];

void dfs(int u, int from) {
    cur.push_back(u);
    for (int v:g[u])if (v != from)dfs(v, u);
}

int ans[N];

void dfs1(int i, int C, int C1) {
    if (i == 0)return;
    ans[cur[i]] = C + 1;
    for (int j = C; j <= C; j++) {
        for (int k = C1; k <= C1; k++) {
            for (int s = 0; s < 3; s++) {
                if (j == k || j == s || k == s)continue;
                if (dp[i][j][k] == dp[i - 1][k][s] + c[j][cur[i]]) {
                    dfs1(i - 1, k, s);
                    return;
                }
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> c[0][i];
    for (int i = 1; i <= n; i++)cin >> c[1][i];
    for (int i = 1; i <= n; i++)cin >> c[2][i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)if (g[i].size() >= 3)return cout << -1 << endl, 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            dfs(i, -1);
            break;
        }
    }
    cur.insert(cur.begin(), 0);
    memset(dp, 0x3f, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    int ans = 1e18;
    int res1 = -1, res2 = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int s = 0; s < 3; s++) {
                    if (j == k || j == s || k == s)continue;
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][k][s] + c[j][cur[i]]);
                    if (i == n) {
                        if (dp[i][j][k] < ans)ans = dp[i][j][k], res1 = j, res2 = k;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    dfs1(n, res1, res2);
    for (int i = 1; i <= n; i++)cout << ::ans[i] << " ";
    cout << endl;
}