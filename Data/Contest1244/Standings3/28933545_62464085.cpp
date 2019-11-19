#include <bits/stdc++.h>

using namespace std;

long long q, f, f1, f2, f3, f4, cnt, cnt1;

int main() {
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> f >> f1 >> f2 >> f3 >> f4;
        cnt = (f + f2 - 1) / f2;
        cnt1 = (f1 + f3 - 1) / f3;
        if (cnt + cnt1 <= f4) {
            cout << cnt << " " << cnt1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
