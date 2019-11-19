#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int idl = 0, idr = n - 1;
    while (k && idl < idr) {
        while (idr && a[idr] == a[idr - 1]) --idr;
        while (idl < n - 1 && a[idl] == a[idl + 1]) ++idl;
        if (idl == n - 1 || idr == 0) break;
        if (idl < n - 1 - idr) {
            if (k < (a[idl + 1] - a[idl]) * (idl + 1)) {
                a[idl] += k / (idl + 1);
                k = 0;
            }
            else {
                k -= (a[idl + 1] - a[idl]) * (idl + 1);
                ++idl;
            }
        }
        else {
            if (k < (a[idr] - a[idr - 1]) * (n - idr)) {
                a[idr] -= k / (n - idr);
                k = 0;
            }
            else {
                k -= (a[idr] - a[idr - 1]) * (n - idr);
                --idr;
            }
        }
    }
    cout << max(0ll, a[idr] - a[idl]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
