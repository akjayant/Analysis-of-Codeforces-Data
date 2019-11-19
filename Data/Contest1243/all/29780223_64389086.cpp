#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int nn = n;
    int res = n;
    for (int i = 2; i * i <= nn; ++i) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            res = __gcd(res, i);
        }
    }
    if (n > 1)
        res = __gcd(res, n);
    cout << res << endl;
    return 0;
}