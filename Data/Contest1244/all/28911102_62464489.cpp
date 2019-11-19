// qdd on Oct 13, 2019

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int ceil_div(int x, int y) {
    return (x + (y - 1)) / y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, a, b, c, d, k;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d >> k;
        if (ceil_div(a, c) + ceil_div(b, d) <= k) {
            cout << ceil_div(a, c) << ' ' << ceil_div(b, d) << '\n';
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}