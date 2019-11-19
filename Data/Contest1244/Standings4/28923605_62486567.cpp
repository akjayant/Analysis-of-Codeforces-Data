#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using ll = long long;
using vll = vector<ll>;
#define szof(a) (int)a.size()
#define allof(a) a.begin(), a.end()
#define f first
#define s second

int n, c[4][100005];
vi g[100005];
int colour[100005];
int nxt[100005];
int main() {
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int t = 0; t < 3; ++t)
        for (int i = 1; i <= n; ++i) scanf("%d", &c[t][i]);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int root;
    for (int i = 1; i <= n; ++i) {
        if (szof(g[i]) > 2) {
            printf("-1\n");
            return 0;
        }
        if (szof(g[i]) == 1) {
            root = i;
        }
    }

    nxt[root] = g[root][0];
    int pre = root;
    int x = nxt[root];
    while (true) {
        if (szof(g[x]) == 1) {
            nxt[x] = -1;
            break;
        } else {
            if (g[x][0] == pre)
                nxt[x] = g[x][1];
            else
                nxt[x] = g[x][0];
        }
        pre = x;
        x = nxt[x];
        }
    // 6 possibilities
    pair<ll, ii> ans = { 1e18, { -1, -1 } };
    for (int t1 = 0; t1 < 3; ++t1) {
        for (int d = -1; d <= 1; ++d) {
            if (d == 0) continue;
            ll cost = 0;
            int t = t1;
            int u = root;
            for (int i = 1; i <= n; ++i) {
                cost += c[t][u];
                u = nxt[u];
                t += d + 3;
                t %= 3;
            }
            ans = min(ans, { cost, { t1, d } });
        }
    }
    printf("%lld\n", ans.f);
    int t1 = ans.s.f, d = ans.s.s;
    int t = t1;
    int u = root;
    for (int i = 1; i <= n; ++i) {
        // printf("%d ", t + 1);
        colour[u] = t + 1;
        // u = g[u][0];
        u = nxt[u];
        t += d + 3;
        t %= 3;
    }
    for (int i = 1; i <= n; ++i) printf("%d ", colour[i]);
}