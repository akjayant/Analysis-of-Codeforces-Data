#include <bits/stdc++.h>
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#define int long long

using namespace std;

const int mod = 1e9 + 7;

int power(int x, int y) {
    if (y == 0)
        return 1;
    else if (y == 1)
        return x;
    else {
        if (y % 2 == 0) {
            int kek = power(x, y / 2);
            return (kek * kek) % mod;
        }
        else {
            return (power(x, y - 1) * x) % mod;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int x = power(2, m) - 1;
    cout << power(x, n) << "\n";
    return 0;
}
