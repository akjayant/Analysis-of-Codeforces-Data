#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5;
const int INF = 1e18;

vector <int> a[N];
int n;

int c[N][3], color[N];

int help[3], cnt, kek[N];
int ans[N];
int f[3];

void dfs(int u, int p, int h) {
    cnt += c[u][help[h % 3]];
    for (int v : a[u]) {
        if (v != p) {
            dfs(v, u, h + 1);
        }
    }
}

void put(int u, int p, int h) {
    ans[u] = f[h % 3];
    for (int v : a[u]) {
        if (v != p) {
            put(v, u, h + 1);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef arrias
    freopen("true.txt", "r", stdin);
#endif
    cin >> n;
    for (int j = 0; j < 3; ++j) {
        for (int i = 1; i <= n; ++i) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        if (a[i].size() > 2) {
            cout << -1;
            return 0;
        }
        if (a[i].size() == 1) {
            root = i;
        }
    }
    int res = INF;
    for (int cur = 0; cur < 3; ++cur) {
        for (int c = 0; c < 3; ++c) {
            if (c == cur) continue;
            help[0] = cur;
            help[1] = c;
            help[2] = 3 - cur - c;
            cnt = 0;
            dfs(root, -1, 0);
            if (cnt < res) {
                res = cnt;
                f[0] = help[0];
                f[1] = help[1];
                f[2] = help[2];
            }
        }
    }
    put(root, -1, 0);
    cout << res << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}
