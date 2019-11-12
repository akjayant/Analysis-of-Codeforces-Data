#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

bool MULTI_TEST = false;
const int MOD = 1e9 + 7;

int bpow(int n, int k) {
    if (k == 0) {
        return 1;
    }
    int t = bpow(n, k / 2);
    if (k % 2 == 0) {
        return t * t % MOD;
    }
    return t * t % MOD * n % MOD;
}

void solve() {
    int n, m;
    cin >> n >> m;
    cout << bpow((bpow(2, m) - 1 + MOD) % MOD, n);
}

signed main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    if (MULTI_TEST) {
        cin >> t;
    }
    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}

