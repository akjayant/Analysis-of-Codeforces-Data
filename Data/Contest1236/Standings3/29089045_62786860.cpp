#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
 
void solve();

signed main () {
    cout.precision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1; 
    // cin >> t;
    int tt = t;
    while (t--) { 
        solve();
    }
    return 0;
}
const int M = 1e9 + 7;
int exp (int a, int b) {
    if (b == 0)
        return 1;
    int ans = exp(a, b/2);
    ans = (ans * ans) % M;
    if (b & 1) 
        ans = (ans * a) % M;
    return ans;
}
void solve() {
    int n, m;
    cin >> n >> m;
    int ans = exp(2, m) + M - 1;
    ans %= M;
    ans = exp(ans, n);
    cout << ans;
}       
