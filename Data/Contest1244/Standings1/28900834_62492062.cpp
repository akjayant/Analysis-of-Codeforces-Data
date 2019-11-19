#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, p, w, d;
    cin >> n >> p >> w >> d;
    int x = 0;
    bool check = 0;
    for (int i = 0; i < w; ++i) {
        if (x * d > p) break;
        if ((p - x * d) % w == 0) {
            check = 1;
            break;
        }
        ++x;
    }
    if (!check || x + (p - x * d) / w > n) cout << -1;
    else cout << (p - x * d) / w << ' ' << x << ' ' << n - (p - x * d) / w - x;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
