#include <bits/stdc++.h>
#define int long long
#define TTT long long
#define all(x) x.begin(), x.end()
#define forn(n) for (int i = 0; i < n; i++)
#define cint [&](){TTT x; cin >> x; return x;}()
using namespace std;

const int N = 1e5 + 1;
void trymax(int& x, int y) {
    x = max(x, y);
}
void trymin(int& x, int y) {
    x = min(x, y);
}

signed main () {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int k;
        cin >> k;
        int ansx = ceil(1.0 * a / c),
            ansy = ceil(1.0 * b / d);
        if (ansx + ansy > k) cout << -1 << '\n';
        else {
            k -= ansx + ansy;
            cout << ansx + k << ' ' << ansy << '\n';
        }
    }


}
