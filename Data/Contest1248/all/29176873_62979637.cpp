#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
typedef long long ll;
int main()
{
    int t, n, m;
    scanf("%d", &t);
    while (t--)
    {
        ll ans = 0, odd1 = 0, odd2 = 0, even1 = 0, even2 = 0, x;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if(x % 2 == 1) odd1++;
            else even1++;
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d", &x);
            if(x % 2 == 1) odd2++;
            else even2++;
        }
        ans = odd1 * odd2 + even1 * even2;
        printf("%lld\n", ans);
    }
}
