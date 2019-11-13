#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        int gcd = __gcd(a, b);
        cout << (gcd == 1 ? "Finite" : "Infinite") << '\n';
    }
}

int main() {
    #ifdef LOCAL
        freopen("date.in", "r", stdin);
    #endif
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}