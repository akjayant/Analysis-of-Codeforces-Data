#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    for (int _ = 0; _ < k; ++_) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.rbegin(), a.rend());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, min(i + 1, a[i]));
        }
        cout << ans << endl;
    }
    return 0;
}
