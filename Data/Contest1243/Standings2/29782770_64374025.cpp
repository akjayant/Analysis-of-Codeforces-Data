#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int n;
        cin >> n;
        vector< int > a(n);
        for(int j = 0; j < n; j++) cin >> a[j];

        sort(a.rbegin(), a.rend());

        int ans = 0;

        for(int j = 0; j < n; j++) {
            ans = max(ans, min(j + 1, a[j]));
        }
        cout << ans << endl;
    }
    return 0;
}
