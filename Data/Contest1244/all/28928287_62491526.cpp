#include <algorithm>
#include <cstdio>
typedef long long ll;
ll ar[100001];
int main() {
    ll n, l, r, k;
    scanf("%I64d%I64d", &n, &k);
    l = 0; r = n - 1;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", ar + i);
    }
    std::sort(ar, ar + n);
    for (; k > 0 && l < r; ) {
        for (; l < r && ar[l] == ar[l + 1]; ) {
            ++l;
        }
        for (; r > l && ar[r] == ar[r - 1]; ) {
            --r;
        }
        if (l >= r) break;
        if (l + 1 < n - r) {
            ll calc = (ar[l + 1] - ar[l]) * (l + 1);
            if (k >= calc) {
                k -= calc;
                ar[l] = ar[l + 1];
            } else {
                ll len = k / (l + 1);
                ar[l] += len;
                break;
            }
        } else {
            ll calc = (ar[r] - ar[r - 1]) * (n - r);
            if (k >= calc) {
                k -= calc;
                ar[r] = ar[r - 1];
            } else {
                ll len = k / (n - r);
                ar[r] -= len;
                break;
            }
        }
    }
    printf("%I64d", ar[r] - ar[l]);
    return 0;
}
