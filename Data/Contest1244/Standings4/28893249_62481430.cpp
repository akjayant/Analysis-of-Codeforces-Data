#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <limits>
#include <unordered_set>
using namespace std;

using ll = long long;

ll MOD = 1073741824;

const int MAXN = 100005;

ll c[MAXN][3];
int deg[MAXN];
vector<int> sorted;
vector<int> g[MAXN];
int ans[MAXN];

ll dp[MAXN][3][3];

void dfs(int u, int p = - 1) {
    sorted.push_back(u);
    for (int v: g[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>> n;
    for (int i = 1; i <= n; i++) cin >> c[i][0];
    for (int i = 1; i <= n; i++) cin >> c[i][1];
    for (int i = 1; i <= n; i++) cin >> c[i][2];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++; deg[v]++;
        if (deg[u] > 2 || deg[v] > 2) {
            cout << -1;
            return 0;
        }
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int u = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            u = i;
        }
    }
    dfs(u);
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            if (a != b) {
                dp[1][a][b] = c[sorted[0]][a] + c[sorted[1]][b];
            }
        }
    }
    for (int i = 2; i < n; i++) {
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                if (a != b) {
                    dp[i][a][b] = dp[i - 1][3 - a - b][a] + c[sorted[i]][b];
                }
            }
        }
    }
    ll Min = numeric_limits<ll>::max();
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            if (a != b && dp[n-1][a][b] < Min) {
                Min = dp[n-1][a][b];
            }
        }
    }
    vector<int> res;
    bool flag = true;
    for (int a = 0; flag && a < 3; a++) {
        for (int b = 0; flag && b < 3; b++) {
            if (dp[n-1][a][b] == Min) {
                res.push_back(b + 1);
                res.push_back(a + 1);
                for (int i = 2; i < n; i++) {
                    res.push_back(6 - res[i-1] - res[i-2]);
                }
                flag = false;
            }
        }
    }
    reverse(begin(res), end(res));
    for (int i =0; i < n; i++) {
        ans[sorted[i]] = res[i];
    }
    cout << Min << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
