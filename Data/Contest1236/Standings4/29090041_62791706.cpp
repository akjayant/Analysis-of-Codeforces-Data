#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int pwr(int x, int n) {
    if (!n)
        return 1;
    if (n & 1)
        return 1LL * x * pwr(1LL * x * x % MOD, n >> 1) % MOD;
    return pwr(1LL * x * x % MOD, n >> 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    int ans = pwr(pwr(2, m) - 1, n);
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
    return 0;
}
