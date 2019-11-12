#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[10010];


int main()
{
    ll k, t, n, m, i, cnt;

    scanf("%lld", &k);

    while(k--)
    {
        scanf("%lld", &n);

        for(i=0; i<n; i++) scanf("%lld", &a[i]);

        sort(a, a+n);
        ll ans=0;
        for(i=n-1, cnt=1; i>=0; i--, cnt++)
        {
            if(a[i]>=cnt) ans=cnt;
        }
        printf("%lld\n", ans);
    }


    return 0;
}
