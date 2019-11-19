#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int main() {

    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        ll cnt[2] = {};
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            if (x % 2 == 0) cnt[0]++;
            else cnt[1]++;
        }

        int m; scanf("%d", &m);
        ll cntt[2] = {};
        for (int i = 0; i < m; i++) {
            int x; scanf("%d", &x);
            if (x % 2 == 0) cntt[0]++;
            else cntt[1]++;
        }

        ll ans = cnt[0] * cntt[0] + cnt[1] * cntt[1];
        printf("%lld\n", ans);
    }

    return 0;
}