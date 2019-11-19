#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fast_io    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x)     cerr << #x << " = " << x << "\n"
#define m_p        make_pair
#define se         second
#define fi         first
#define y1         CNik
#define dist(a, b, c, d) sqrt((a - c) * (a - c) + (b - d) * (b - d))

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

template <typename T> using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll INF = 4e18;
const int N = 5e5 + 5;
const ll mod = 1e9 + 7;

ll n, m, dp[N][3], dp1[N][3];

int main() {
    fast_io

    cin >> n >> m;

    dp[0][0] = dp[0][1] = 1;
    for(int i = 1; i <= m; ++i) {
        if(i >= 2) {
            dp[i][1] = (dp[i - 1][0] + dp[i - 2][0]) % mod;
            dp[i][0] = (dp[i - 1][1] + dp[i - 2][1]) % mod;
        } else {
            dp[i][1] = dp[i - 1][0];
            dp[i][0] = dp[i - 1][1];
        }
    }
    dp1[0][0] = dp1[0][1] = 1;
    for(int i = 1; i <= n; ++i) {
        if(i >= 2) {
            dp1[i][1] = (dp1[i - 1][0] + dp1[i - 2][0]) % mod;
            dp1[i][0] = (dp1[i - 1][1] + dp1[i - 2][1]) % mod;
        } else {
            dp1[i][1] = dp1[i - 1][0];
            dp1[i][0] = dp1[i - 1][1];
        }
    }
    cout << (dp[m][0] + dp[m][1] + dp1[n][0] + dp1[n][1] - 2) % mod << '\n';


	return 0;
}
