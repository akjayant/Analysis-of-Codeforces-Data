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

    cin >> n;
    k = 0;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < n; j++) {
            if (k == 0) {
                k = 1;
                cout << j * n + i << " ";
            } else {
                k = 0;
                cout << j * n + n - i + 1 << " ";
            }
        } cout << endl;
    }
    return 0;
}
