#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long xpow(long long a, long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, m;
    cin >> n >> m;
    long long ans = xpow(2, m);
    ans = (ans - 1 + MOD) % MOD;
    ans = xpow(ans, n);
    cout << ans << endl;
    return 0;
}