#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 500005;
const int mod = 1000000007;

int fun(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1) {
        return fun(a, b - 1) * a % mod;
    } else {
        int c = fun(a, b / 2);
        return (c * c) % mod;
    }
}

signed main() {
    int a, b, c, d, e, f, g, h, n, m, i, j, k;
    int x, y, t, q, l, r, p, z;
    string s = "";

    cin >> n >> m;
    a = fun(2, m) - 1;
    cout << fun(a, n);
    return 0;
}
