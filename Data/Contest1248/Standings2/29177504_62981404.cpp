#include <bits/stdc++.h>
using namespace std;

const int maxn = 100100;

long long a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    long long mi = 0, ma = 0;
    for (int i = 0; i < n / 2; i++)
    {
        mi += a[i];
    }
    for (int i = n / 2; i < n; i++)
    {
        ma += a[i];
    }
    printf("%lld\n", mi * mi + ma * ma);
    return 0;
}
