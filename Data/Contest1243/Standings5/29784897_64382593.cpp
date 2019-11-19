#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define int long long

bool is_p(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if (is_p(n)) {
        cout << n;
    } else {
        int ans = n;
        for (int i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                ans = __gcd(ans, i);
                n /= i;
            }
        }
        if (n > 1) {
            ans = __gcd(ans, n);
        }
        cout << ans;
    }
}