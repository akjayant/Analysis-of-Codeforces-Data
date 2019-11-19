#include <bits/stdc++.h>

using namespace std;

#define LL long long int
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int oo = 1e8;
// const LL oo = 1e16 + 5;
const int MOD = 1e9 + 7;
const int N = 1e6+5;
// const int MOD = 998244353;
// const long double PI = acos(-1);

int f[N];
void solve() {
    int m, n, i;
    cin >> n >> m;
    int z = max(n, m);
    f[0] = 1; f[1] = 1;
    for (i=2;i<=z;i++) {
        f[i] = f[i-1] + f[i-2];
        if (f[i] >= MOD) f[i] -= MOD;
    }
    LL ans = f[n] + f[m];
    ans = 2 * (ans - 1);
    ans %= MOD;
    if (ans < 0) ans += MOD;
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