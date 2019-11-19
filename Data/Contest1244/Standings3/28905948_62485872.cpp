#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define int long long
#define ll long long
#define ins insert
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define ld long double
#define rsz resize
#define pii pair<int, int>

using namespace std;

mt19937 rnd(time(nullptr));

const long long INF = 1e18, N = 1e5 + 10;
vector<int> g[N];
int dp[N][3][3], c[N][3];
vector<int> a;

void dfs(int v, int pr) {
    a.pb(v);
    for (int u : g[v]) {
        if (u != pr) {
            dfs(u, v);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i][0];
    for (int i = 0; i < n; i++) cin >> c[i][1];
    for (int i = 0; i < n; i++) cin >> c[i][2];
    for (int w = 0; w < n - 1; w++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].pb(u);
        g[u].pb(v);
    }
    for (int i = 0; i < n; i++) {
        if (g[i].size() > 2) {
            cout << -1;
            return 0;
        }
    }
    for (int w = 0; w < n; w++) if (g[w].size() == 1) {
        dfs(w, -1);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                if (i != j) dp[1][i][j] = c[a[0]][i] + c[a[1]][j];
            }
        }
        for (int q = 2; q < n; q++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (k == j) continue;
                    int i = 3 - j - k;
                    dp[q][j][k] = dp[q - 1][i][j] + c[a[q]][k];
                }
            }
        }
        int ans = INF;
        pii id;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                if (ans > dp[n - 1][i][j]) {
                    ans = dp[n - 1][i][j];
                    id = {i, j};
                }
            }
        }
        cout << ans << "\n";
        vector<int> kek(n);
        kek[a[n - 1]] = id.ss + 1;
        for (int i = 0; i < n - 1; i++) {
            kek[a[n - i - 2]] = id.ff + 1;
            int a = id.ff, b = id.ss, c = 3 - a - b;
            id = {c, a};
        }
        for (int elem : kek) cout << elem << ' ';
        return 0;
    }
    cout << -1;
    return 0;
}
