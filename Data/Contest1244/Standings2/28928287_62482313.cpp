#include <algorithm>
#include <cstdio>
typedef long long ll;
int main() {
    ll n, p, d, w;
    int flag = 0;
    scanf("%I64d%I64d%I64d%I64d", &n, &p, &w, &d);
    for (ll i = 0; i <= w; ++i) {
        ll x = p - d * i;
        if (x < 0 || flag) break;
        if (x % w == 0) {
            if (x / w + i <= n) {
                flag = 1;
                printf("%I64d %I64d %I64d\n", x / w, i, n - (x / w + i));
            }
        }
    }
    if (!flag) puts("-1");
    return 0;
}
