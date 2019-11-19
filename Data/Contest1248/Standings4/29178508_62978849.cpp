#include<bits/stdc++.h>
using namespace std;
long long t,n,a,b,c,d,m;
int main()
{
    scanf("%lld",&t);
    for (int iii=1;iii<=t;++iii)
    {
        a=b=c=d=0;
        scanf("%lld",&n);
        for (int i=1;i<=n;++i)
        {
            long long x;
            scanf("%lld",&x);
            if (x%2==0) a++;else b++;
        }
        scanf("%lld",&m);
        for (int i=1;i<=m;++i)
        {
            long long x;
            scanf("%lld",&x);
            if (x%2==0) c++;else d++;
        }
        long long ans;
        ans=a*c+b*d;
        printf("%lld\n",ans);
    }
    return 0;
}
