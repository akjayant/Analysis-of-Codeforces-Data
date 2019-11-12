#include <bits/stdc++.h>
using namespace std;

signed main () {
#ifdef _IANE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> g(n);

        for (int i = 0; i < n; ++i)
            cin >> g[i];

        sort(g.begin(), g.end());
        reverse(g.begin(), g.end());

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, min(i + 1, g[i]));
        }

        cout << ans << "\n";
    }

    return 0;
}
