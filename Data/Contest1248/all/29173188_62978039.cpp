#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
ll T, n, p[N], m, q[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        ll cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        rep(i, 1, n) {
            scanf("%lld", &p[i]);
            if (p[i] % 2) cnt1++; else cnt2++;
        }
        cin >> m;
        // puts("ok");
        rep(i, 1, m) {
            scanf("%lld", &q[i]);
            if (q[i] % 2) cnt3++; else cnt4++;
        }
        printf("%lld\n", cnt1 * cnt3 + cnt2 * cnt4);
    }
    return 0;
}
