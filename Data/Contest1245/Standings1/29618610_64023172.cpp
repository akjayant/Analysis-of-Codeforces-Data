//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,popcnt,avx,avx2,tune=native")
           
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
           
using namespace std;
using namespace __gnu_pbds;
           
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
           
using matrix = vector<vector<ll>>;
template<typename T>
using kawaii_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
           
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
//#define int long long;
           
void FAST_IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout.setf(ios::fixed);
    //cout.precision(20);
    #ifndef _offline
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
}

const int MAXN = 31;
ll dp[MAXN][2][2][2][2][2];

signed main() {
    FAST_IO();
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        memset(dp, 0, sizeof(dp));
        dp[MAXN - 1][0][0][0][0][0] = 1;
        for (int i = MAXN - 2; i >= 0; --i) {
            for (int f1 = 0; f1 <= 1; ++f1) {
                for (int f2 = 0; f2 <= 1; ++f2) {
                    for (int f3 = 0; f3 <= 1; ++f3) {
                        for (int f4 = 0; f4 <= 1; ++f4) {
                            for (int f5 = 0; f5 <= 1; ++f5) {
                                if ((f1 == 1 || !(l & (1 << i))) && (f3 == 1 || !(l & (1 << i)))) {
                                    dp[i][f1][f2 | (!!(r & (1 << i)))][f3][f4 | (!!(r & (1 << i)))][f5] += dp[i + 1][f1][f2][f3][f4][f5];
                                }
                                if ((f1 == 1 || !(l & (1 << i))) && (f4 == 1 || !!(r & (1 << i)))) {
                                    dp[i][f1][f2 | (!!(r & (1 << i)))][f3 | (!(l & (1 << i)))][f4][f5] += dp[i + 1][f1][f2][f3][f4][f5];
                                }
                                if ((f2 == 1 || !!(r & (1 << i))) && (f3 == 1 || !(l & (1 << i)))) {
                                    dp[i][f1 | (!(l & (1 << i)))][f2][f3][f4 | (!!(r & (1 << i)))][f5] += dp[i + 1][f1][f2][f3][f4][f5];
                                }
                                if ((f2 == 1 || !!(r & (1 << i))) && (f4 == 1 || !!(r & (1 << i)))) {
                                    dp[i][f1 | (!(l & (1 << i)))][f2][f3 | (!(l & (1 << i)))][f4][1] += dp[i + 1][f1][f2][f3][f4][f5];
                                }
                            }
                        }
                    }
                }
            }
        }
        ll ans = 0;
        for (int f1 = 0; f1 <= 1; ++f1) {
            for (int f2 = 0; f2 <= 1; ++f2) {
                for (int f3 = 0; f3 <= 1; ++f3) {
                    for (int f4 = 0; f4 <= 1; ++f4) {
                        ans += dp[0][f1][f2][f3][f4][0];
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}  
