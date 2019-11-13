// qdd on Oct 17, 2019

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    while (b >= 1 && c >= 2) b -= 1, c -= 2, ans += 3;
    while (a >= 1 && b >= 2) a -= 1, b -= 2, ans += 3;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}