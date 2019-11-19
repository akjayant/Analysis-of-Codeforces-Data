#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, col[maxn];
pair<int, int> pre[maxn][3][3];
ll c[maxn][3], mn[2][3], f[maxn][3][3];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &c[j][i]);
        }
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    memset(f, 0x3f, sizeof(f));
    function<void(int, int)> dfs = [&](int v, int fa) {
        int cnt = 0;
        vector<int> H;
        for (int u : G[v]) if (u ^ fa) {
            dfs(u, v), cnt++;
            H.push_back(u);
        }
        G[v] = H;
        if (cnt > 1) printf("-1\n"), exit(0);
        if (!cnt) {
            for (int i = 0; i < 3; i++) f[v][i][i] = c[v][i];
            return;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i == j || i == k) continue;
                    ll t = f[G[v][0]][j][k] + c[v][i];
                    if (t < f[v][i][j]) {
                        f[v][i][j] = t;
                        pre[v][i][j] = make_pair(j, k);
                    }
                }
            }
        }
    };
    int rt = -1;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() == 1) { rt = i; break; }
    }
    if (rt == -1) printf("-1\n"), exit(0);
    dfs(rt, 0);
    ll ans = LLONG_MAX;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (f[rt][i][j] < ans) ans = f[rt][i][j];
        }
    }
    cout << ans << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (f[rt][i][j] == ans) {
                while (G[rt].size()) {
                    col[rt] = i;
                    int x = i, y = j;
                    i = pre[rt][x][y].first;
                    j = pre[rt][x][y].second;
                    rt = G[rt][0];
                }
                col[rt] = i;
                for (int i = 1; i <= n; i++) {
                    printf("%d ", col[i] + 1);
                }
                return 0;
            }
        }
    }
    return 0;
}