
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

#define X first
#define Y second
#define A(x) get<0>(x)
#define B(x) get<1>(x)
#define C(x) get<2>(x)
#define D(x) get<3>(x)

mt19937 gen(228);

#ifdef DEBUG
#define dbg(x) cout << "[dbg " << __LINE__ << "] " << x << endl
#else
#define dbg(x) ((void)0)
#endif

constexpr ll MOD = 1'000'000'007;

constexpr int N = 100005;

ll dp [4][N];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[2][0] = 0;
    dp[3][0] = 0;

    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[3][1] = 1;

    for (int i = 2; i < max(m, n); i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if ((((k >> 1) & 1) ^ (j & 1)) == 0 && (k | (j << 1)) != 7 && (k | (j << 1)) != 0) {
                    dp[j][i] += dp[k][i - 1];
                    dp[j][i] %= MOD;
                }
            }
        }
    }

    ll ans = dp[0][m - 1] + dp[1][m - 1] + dp[2][m - 1] + dp[3][m - 1] + dp[0][n-1] + dp[1][n-1] + dp[2][n-1] + dp[3][n-1] - 2 + MOD;
    ans %= MOD;

    cout << ans << "\n";

    return 0;
}
