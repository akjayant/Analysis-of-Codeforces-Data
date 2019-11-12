#include <bits/stdc++.h>
using namespace std;

int main () {
        int T; cin >> T;
        while (T--) {
                int a, b, c; cin >> a >> b >> c;
                int ans = 0;
                int cnt = min(b, c/2);
                ans = ans + 3 * cnt;
                b -= cnt, c -= 2*cnt;
                cnt = min(a, b/2);
                ans = ans + 3 * cnt;
                a -= cnt, b -= 2*cnt;
                cout << ans << endl;
        }
        return 0;
}