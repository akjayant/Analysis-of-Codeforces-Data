//#pragma GCC target ("avx2,sse2")
//#pragma GCC optimization ("Ofast")
//#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree <int, null_type, less_equal <int>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define db long double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fi first
#define se second
#define mp make_pair
#define up_b upper_bound
#define low_b lower_bound
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define endl "\n"

#define left fsdkfsdfsdfd
#define sum dfsdfsdfsdf
#define assign sdkfskdfkk

#define int long long

using namespace std;

void dout() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

int bit(signed x) {
    return __builtin_popcount(x);
}
int bit(ll x) {
    return __builtin_popcountll(x);
}

const int N = 1e5 + 7, MOD = 1e9 + 7;
int n, dp[N][2], w[N], m[N];
string s;

void solve(int tc) {
    // check for (int i = 0; i < n; j++)
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0;
            return;
        }
    }
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == 'u' && s[i] == 'u') {
            w[i] = 1;
        }
        if (s[i - 1] == 'n' && s[i] == 'n') {
            m[i] = 1;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = 0;
        if (w[i] || m[i]) {
            dp[i][1] += (dp[i - 1][0]) % MOD;
        }
    }
    cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int tc = 1;
//    cin >> tc;
    for (int i = 0; i < tc; i++) {
        solve(i);
//        cleanup();
    }
}
