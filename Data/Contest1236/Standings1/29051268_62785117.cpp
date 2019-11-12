#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define F(i, n) for(int i = 0; i < n; ++ i)

int32_t main() {
    ios_base::sync_with_stdio(false);
    int Q; cin >> Q;
    F(q, Q) {
        int a, b, c; cin >> a >> b >> c;
        int ans = 0;
        F(i, a + 1) {
            int rem = b - 2 * i;
            if(rem < 0) break;
            int cur = i * 3 + min(rem, c / 2) * 3;
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
}
