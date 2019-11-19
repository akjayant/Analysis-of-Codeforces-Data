#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, m, cnt1, cnt2, cnt3, cnt4;
ll ans;
void solve() {
    ans = cnt1 = cnt2 = cnt3 = cnt4 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) { int x;
        scanf("%d", &x);
        if (x % 2) cnt1 ++;
        else cnt2 ++;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) { int x;
        scanf("%d", &x);
        if (x % 2) cnt3 ++;
        else cnt4 ++;
    }
    ans = (ll)cnt1 * (ll)cnt3 + (ll)cnt2 * (ll)cnt4;
    printf("%lld\n", ans);
}

int main() { int t;
    scanf("%d", &t);
    while (t --) solve();
    return 0;
}