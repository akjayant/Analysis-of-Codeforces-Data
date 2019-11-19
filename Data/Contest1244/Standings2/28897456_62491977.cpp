//#pragma GCC target ("avx2,sse2")
//#pragma GCC optimization ("Ofast")
//#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define db long double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fi first
#define se second
#define mp make_pair
#define endl "\n"
#define int long long
using namespace std;

void dout() {
    cerr << endl;
}

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
const int N = 1e5 + 7, inf = 1e18;
int n, c[3][N], a[N], deg[N], cnt, dp[N][3][3], h[N][3][3], ans[N];
vector <int> q[N];

void dfs(int v, int p = -1) {
    a[++cnt] = v;
    for (auto i : q[v]) {
        if (i != p) {
            dfs(i, v);
        }
    }
}

void getans(int i, int x, int y) {
    ans[a[i]] = x + 1;
    if (i == 2) {
        ans[a[1]] = y + 1;
        return;
    }
    assert(h[i][x][y] != -1);
    getans(i - 1, y, h[i][x][y]);
}

void solve(int tc) {
    cin >> n;
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        q[x].pb(y);
        q[y].pb(x);
        deg[x]++;
        deg[y]++;
    }
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 2) {
            cout << -1;
            return;
        }
        if (deg[i] == 1) {
            root = i;
        }
    }
    dfs(root);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = inf;
                h[i][j][k] = -1;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            dp[1][i][j] = c[i][a[1]];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            dp[2][i][j] = min(dp[2][i][j], dp[1][j][0] + c[i][a[2]]);
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (j != k && j != l && k != l) {
                        if (dp[i][j][k] > dp[i - 1][k][l] + c[j][a[i]]) {
                            dp[i][j][k] = dp[i - 1][k][l] + c[j][a[i]];
                            h[i][j][k] = l;
                        }
                    }
                }
            }
        }
    }
    int res = inf;
    pii tmp = {-1, -1};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (res > dp[n][i][j]) {
                res = dp[n][i][j];
                tmp = {i, j};
            }
        }
    }
    getans(n, tmp.fi, tmp.se);
    cout << res << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int tc = 1;
//    cin >> tc;
    for (int i = 0; i < tc; i++) {
        solve(i);
//        cleanup();
    }
}
