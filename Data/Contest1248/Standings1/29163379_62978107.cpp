#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, m, f, cnt0 = 0, cntM0 = 0, cnt1 = 0, cntM1 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f;
        if (f % 2 == 0) {
            cnt0++;
        } else {
            cnt1++;
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> f;
        if (f % 2 == 0) {
            cntM0++;
        } else {
            cntM1++;
        }
    }
    cout << cnt0 * cntM0 + cnt1 * cntM1 << endl;
}

int main() {
    long long q;
    cin >> q;
    while (q > 0) {
        solve();
        q--;
    }
}
