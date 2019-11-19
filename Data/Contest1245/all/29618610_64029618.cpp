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
    cout.setf(ios::fixed);
    cout.precision(20);
    #ifndef _offline
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
}

const int MAXN = 10;
ld dp[MAXN][MAXN];
int h[MAXN][MAXN];

signed main() {
    FAST_IO();
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            cin >> h[i][j];
        }
    }
    dp[0][0] = 0;
    dp[0][1] = 6;
    dp[0][2] = 6;
    dp[0][3] = 6;
    dp[0][4] = 6;
    dp[0][5] = 6;
    for (int j = 6; j < MAXN; ++j) {
        for (int k = j - 6; k < j; ++k) {
            dp[0][j] += (dp[0][k] + 1) * (1 / 6.);
        }
    }
    for (int i = 1; i < MAXN; ++i) {
        if (i % 2 == 1) {
            for (int j = MAXN - 1; j >= 0; --j) {
                vector<pii> nxt;
                for (int k = 1; k <= 6; ++k) {
                    if (j + k < MAXN) {
                        nxt.push_back({i, j + k});
                    }
                    else {
                        nxt.push_back({i - 1, MAXN - (j + k - MAXN) - 1});
                    }
                }
                for (auto &[x, y] : nxt) {
                    dp[i][j] += (min(dp[x][y], dp[x - h[x][y]][y]) + 1) * (1 / 6.);
                }
            }
        }
        else {
            for (int j = 0; j < MAXN; ++j) {
                vector<pii> nxt;
                for (int k = 1; k <= 6; ++k) {
                    if (j - k >= 0) {
                        nxt.push_back({i, j - k});
                    }
                    else {
                        nxt.push_back({i - 1, 0 - (j - k) - 1});
                    }
                }
                for (auto &[x, y] : nxt) {
                    dp[i][j] += (min(dp[x][y], dp[x - h[x][y]][y]) + 1) * (1 / 6.);
                }
            }
        }
    }
    cout << dp[MAXN - 1][0] << '\n';
}  
