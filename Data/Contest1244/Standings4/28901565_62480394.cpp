#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define file freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
const int maxn = 1e5 + 5;
int col[maxn][3];
int p[maxn][3][3];
vector<int>b;
vector<int>g[maxn];
void dfs(int v, int p = -1) {
    b.pb(v);
    for (auto to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
    }
}
int dp[maxn][3][3];
signed main() {
    fast;
    srand(time(0));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> col[i][0];
    }
    for (int i = 0; i < n; i++) {
        cin >> col[i][1];
    }
    for (int i = 0; i < n; i++) {
        cin >> col[i][2];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u - 1].pb(v - 1);
        g[v - 1].pb(u - 1);
    }
    for (int i = 0; i < n; i++) {
        if (g[i].size() >= 3) {
            cout << -1;
            return 0;
        }
    }
    int lv = -1;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            lv = i;
            break;
        }
    }
    if (lv == -1) {
        cout << min({col[0][0], col[0][1], col[0][2]});
        return 0;
    }
    dfs(lv);
    vector<int>aa = {0, 1, 2};
    vector<int>mina;
    int ans = 1e18;
    do {
        int nowans = 0;
        for (int i = 0; i < n; i++) {
            nowans += col[b[i]][aa[i % 3]];
        }
        if (nowans < ans) {
            ans = nowans;
            mina = aa;
        }
    } while (next_permutation(all(aa)));
    cout << ans << '\n';
    int anus[n];
    for (int i = 0; i < n; i++) {
        anus[b[i]] = mina[i % 3];
    }
    for (int i = 0; i < n; i++) {
        cout << anus[i] + 1 << ' ';
    }
    return 0;
}
