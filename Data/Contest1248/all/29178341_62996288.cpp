#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define forn(i, n) for(int i=0;i<(n);++i)
#define clr(ar, val) memset(ar, val, sizeof(ar))

using namespace std;

typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<ld, ld> point;

const int MAXN = int(2e5) + 200;
const int INF = int(1e9) + 10;
const long long LINF = 1LL * INF * INF;
const int md = int(1e9) + 7;
const ld eps = 1e-9;
const ld PI = 3.1415926535897932384626433832795l;

int n, m;

long long func(int r, int c) {
    vector<long long> dp(r + 3);
    dp[1] = 2;
    for (int i = 1; i < r; ++i) {
        dp[i + 1] = (dp[i + 1] + dp[i]) % md;
        dp[i + 2] = (dp[i + 2] + dp[i]) % md;
        if (i + 2 > r) {
            dp[i + 1] = (dp[i + 1] + dp[i]) % md;
        }
    }
    return dp[r] % md;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    long long ans = (func(n, m) + func(m, n)) % md;
    ans = (ans - 2 + md) % md;
    cout << ans << endl;
    return 0;
}
