#include <bits/stdc++.h>

#define int long long
#define in(x) scanf("%lld", &x)

using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

signed main()
{
    int n;
    in(n);

    for (int i = 0; i < n; i++)
        in(a[i]);
    
    sort(a, a + n);

    int s1 = 0, s2 = 0;
    for (int i = 0; i < n / 2; i++)
        s1 += a[i];
    
    for (int i = n / 2; i < n; i++)
        s2 += a[i];
    
    printf("%lld", s1 * s1 + s2 * s2);

    return 0;
}