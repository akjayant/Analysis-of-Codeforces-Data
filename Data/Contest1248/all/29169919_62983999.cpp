#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
ll a[MAXN];

int main() {
    int n, tmp;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    tmp = n / 2;
    ll h = 0, r = 0;
    for (int i = 1; i <= n; ++i) {
        if (i <=tmp)
            h += a[i];
        else
            r += a[i];
    }
    printf("%lld\n", h * h + r * r);
    return 0;
}