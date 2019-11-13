#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k; cin >> k;
    while (k--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) if (a[j] >= i) cnt++;
            if (cnt >= i) ans = max(ans, i);
        }
        cout << ans << '\n';
    }
    return 0;
}
