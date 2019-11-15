#include <bits/stdc++.h>

using namespace std;

#define int long long

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);

int32_t main() {
    #ifdef THERE
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        //freopen("common.in", "r", stdin);
        //freopen("common.out", "w", stdout);
    #endif
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b, c, ans = 0;
        cin >> a >> b >> c;
        for (int x = 0; x <= a; x++) {
            if (b < 2 * x) break;
            ans = max(ans, 3 * (x + min(b - 2 * x, c / 2)));
        }
        cout << ans << "\n";
    }
    return 0;
}
