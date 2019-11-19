#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define pf push_front
#define ft first
#define sc second
using namespace std;
const ll maxn = 100500, inf = 1e18;
vector <ll> gr[maxn];
ll c[3][maxn];
ll used[maxn];
vector <ll> ord;
void dfs(ll v, ll k) {
    ord.pb(v);
    for (ll u : gr[v]) {
        if (u != k) {
            dfs(u, v);
        }
    }
}
ll dp[maxn][3][3];
ll ans[maxn];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    for (int d = 0; d < n; d++) {
        cin >> c[0][d];
    }
    for (int d = 0; d < n; d++) {
        cin >> c[1][d];
    }
    for (int d = 0; d < n; d++) {
        cin >> c[2][d];
    }
    for (int d = 0; d < n - 1; d++) {
        ll v, u;
        cin >> v >> u;
        v--; u--;
        gr[v].pb(u);
        gr[u].pb(v);
    }
    ll root = -1;
    for (int d = 0; d < n; d++) {
        if(gr[d].size() > 2) {
            cout << "-1";
            return 0;
        }
        if (gr[d].size() == 1 && root == -1) {
            root = d;
        }
    }
    dfs(root, -1);
    for (int d = 0; d < 3; d++) {
        for (int i = 0; i < 3; i++) {
            dp[0][d][i] = c[d][root];
        }
    }
    for (int i = 1; i < n; i++) {
        dp[i][0][1] = dp[i - 1][1][2] + c[0][ord[i]];
        dp[i][0][2] = dp[i - 1][2][1] + c[0][ord[i]];
        dp[i][1][2] = dp[i - 1][2][0] + c[1][ord[i]];
        dp[i][1][0] = dp[i - 1][0][2] + c[1][ord[i]];
        dp[i][2][0] = dp[i - 1][0][1] + c[2][ord[i]];
        dp[i][2][1] = dp[i - 1][1][0] + c[2][ord[i]];
    }
    ll min1 = inf, rem1 = 0, rem2 = 0;;
    for (int d = 0; d < 3; d++) {
        for (int j = 0; j < 3; j++) {
            if (d != j) {
                if (min1 > dp[n - 1][d][j]) {
                    min1 = dp[n - 1][d][j];
                    rem1 = d;
                    rem2 = j;
                }
            }
        }
    }
    cout << min1 << "\n";
    //cout << rem1 << " " << rem2 << "\n";
    ans[ord[n - 1]] = rem1;
    for (int d = n - 2; d >= 0; d--) {
        ll rem1k = rem2;
        rem2 = (0 + 1 + 2) - rem1 - rem2;
        rem1 = rem1k;
        ans[ord[d]] = rem1;
    }
    for (int d = 0; d < n; d++) {
        cout << ans[d] + 1 << " ";
    }
}
