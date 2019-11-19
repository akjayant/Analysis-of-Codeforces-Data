#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define ld long double
#define ll long long
#define TIME 1.0*clock()/CLOCKS_PER_SEC

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 3e5 + 10;
const ll MOD = 1e9 + 7;
const int rx[4] = {-1, 0, 1, 0};
const int ry[4] = {0, 1, 0, -1};
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int hx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int hy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const ld eps = 1e-7;
const double pi = acos(-1.0);
const int INF = 2e9;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    ll dp[max(n, m) + 1];
    dp[0] = 2;
    dp[1] = 4;
    for (int i = 2; i < n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    ll ans1 = dp[n - 1];
    for (int i = max(2, n); i < m; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    ans1 = (ans1 + dp[m - 1]) % MOD;
    ans1 -= 2;
    if (ans1 < 0) ans1 += MOD;
    cout << ans1 << endl;
    return 0;
}