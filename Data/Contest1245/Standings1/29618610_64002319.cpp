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

const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 100;
ll dp[MAXN];

signed main() {
    FAST_IO();
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
        if (dp[i] >= mod) {
            dp[i] -= mod;
        }
    }
    string s;
    cin >> s;
    int n = s.length();
    ll ans = 1;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0 << '\n';
            return 0;
        } 
        if (s[i] == 'u') {
            if (i == 0 || s[i - 1] != 'u') {
                ans = (ans * dp[cur]) % mod;
                cur = 1;
            }
            else {
                cur++;
            }
        }
        else if (s[i] == 'n') {
            if (i == 0 || s[i - 1] != 'n') {
                ans = (ans * dp[cur]) % mod;
                cur = 1;
            }
            else {
                cur++;
            }
        }
        else {
            ans = (ans * dp[cur]) % mod;
            cur = 0;
        }
    }
    ans = (ans * dp[cur]) % mod;
    cout << ans << '\n';
}  
