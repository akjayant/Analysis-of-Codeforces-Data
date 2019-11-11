/*
................
....@@@@@@@.....
...@.......@....
..@...@.....@...
.@....@@.....@..
@.....@.@.....@.
@@@@@@@@@@@@@@@@
.@....@...@...@.
..@...@....@..@.
...@..@.....@@..
....@@@@@@@@....
................
*/

//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
 
#define X first
#define Y second
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ll long long
//#define int long long

int gcd(int a, int b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}

signed solve() {
    
    string s;
    cin >> s;

    for (char ch : s) {
        if (ch == 'w' || ch == 'm') {
            cout << "0\n";
            return 0;
        }
    }

    int n = s.size();
    const int mod = 1e9 + 7;

    vector<ll> dp(n);

    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1];
        if (s[i] == 'u' && s[i - 1] == 'u' || s[i] == 'n' && s[i - 1] == 'n')
            dp[i] += (i > 1 ? dp[i - 2] : 1);
        dp[i] %= mod;
    }

    cout << dp[n - 1] << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }
}