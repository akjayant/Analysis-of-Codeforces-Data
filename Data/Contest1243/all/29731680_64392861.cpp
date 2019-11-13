#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        reverse(a + 1, a + 1 + n);
        int ans = 1;
        for (int i = 1; i <= n; i++)
            if (a[i] >= i)
                ans = i;
        printf("%d\n", ans);
    }
}