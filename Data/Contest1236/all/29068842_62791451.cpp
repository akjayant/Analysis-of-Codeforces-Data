#include <bits/stdc++.h>

using namespace std;

#define LL long long int
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int oo = 1e9;
// const LL oo = 1e16 + 5;
const int MOD = 1e9 + 7;
const int N = 2e5+5;
// const int MOD = 998244353;
// const long double PI = acos(-1);

LL powermod(LL a, LL b) {
    if (b == 0) return 1;
    LL res = powermod(a, b/2);
    res = (res * res)%MOD;
    if (b & 1) {
        res = (res * a)%MOD;
    }
    return res;
}

void solve() {
    LL n, m, r;
    cin >> n >> m;
    LL ans = powermod(2, m) - 1;
    if (ans < 0) ans += MOD;
    ans = powermod(ans, n);
    cout << ans << '\n';
}

int main() {
    FASTIO; int t = 1; 
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        solve();
    }
    return 0;
}