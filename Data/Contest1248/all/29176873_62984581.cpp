#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
typedef long long ll;
int main()
{
    int n;
    int a[MAXN];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 +n);
    ll t1 = 0, t2 = 0;
    for (int i = 1; i <= n; i++) {
        if(i <= n / 2) t1 += a[i];
        else t2 += a[i];
    }
    ll ans = t1 * t1 + t2 * t2;
    printf("%lld\n", ans);
}
