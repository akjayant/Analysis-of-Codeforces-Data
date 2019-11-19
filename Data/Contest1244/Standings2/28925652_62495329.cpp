#include<bits/stdc++.h>
using namespace std;
long long i,i0,n,m,ans,a[100005];
long long k;
int main()
{
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    long long cnta=1,cntb=1;
    for(i=1,i0=n;i<i0;)
    {
        long long da=cnta*(a[i+1]-a[i]);
        long long db=cntb*(a[i0]-a[i0-1]);
        if(cnta<cntb)
        {
            if(k<da)break;
            k-=da;
            cnta++;
            i++;
        }
        else if(k>=db)
        {
            if(k<db)break;
            k-=db;
            cntb++;
            i0--;
        }
        else break;
    }
    long long z=a[i0]-a[i];
    z-=k/min(cnta,cntb);
    printf("%lld\n",max(0ll,z));
    return 0;
}