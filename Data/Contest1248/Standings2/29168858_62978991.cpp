#include <bits\stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int p[maxn], q[maxn];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        int m;
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
            scanf("%d", &q[i]);
        LL a, b;
        a = 0;
        b = 0;
        for (int i = 1; i <= n; i++)
            if (p[i] & 1)
                a++;
            else
                b++;
        LL c = 0, d = 0;
        for (int i = 1; i <= m; i++)
            if (q[i] & 1)
                c++;
            else
                d++;
        long long ans = a * c + b * d;
        printf("%I64d\n", ans);
    }
    return 0;
}