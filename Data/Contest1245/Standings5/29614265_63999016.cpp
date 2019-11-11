#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

void lol_anton() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        bool good = __gcd(a, b) != 1;
        if (good) cout << "Infinite";
        else cout << "Finite";
        cout << '\n';
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    lol_anton();
}