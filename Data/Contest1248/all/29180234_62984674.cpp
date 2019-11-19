#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
typedef long long ll;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n; ++i)
        scanf("%d",&a[i]);
    sort(a + 1,a + 1 + n);
    int mid = n/2;
    ll s1 = 0,s2 = 0;
    for(int i = 1;i <= mid;++i)
        s1 += a[i];
    for(int i = mid + 1;i <= n;++i)
        s2 += a[i];
    printf("%lld\n",s1 * s1 + s2 * s2);
    return 0;
}