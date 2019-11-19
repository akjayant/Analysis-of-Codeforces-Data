#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5+100;

LL n,K;
LL a[maxn],pre[maxn];
bool is_ok(LL x)
{
    LL sum;
    int j=1;
    for(int i=1;i<=n;i++)
    {
        while(j<n&&a[j+1]<=a[i]+x) j++;
        sum=i*a[i]-pre[i]+pre[n]-pre[j]-(a[i]+x)*(n-j);
        if(sum<=K) return 1;
    }
    j=n;
    for(int i=n;i>=1;i--)
    {
        while(j>1&&a[j-1]>=a[i]-x) j--;
        sum=(a[i]-x)*(j-1)-pre[j-1]+pre[n]-pre[i]-(n-i)*a[i];
        if(sum<=K) return 1;
    }
    return 0;
}
int main()
{
    LL m,i,j,x,y;
    int T;
    T=1;
    while(T--)
    {
        scanf("%I64d%I64d",&n,&K);
        for(i=1;i<=n;i++)
        {
            scanf("%I64d",&a[i]);
        }
        sort(a+1,a+1+n);
        for(i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+a[i];
        }
        LL l,r,mid;
        if(is_ok(0))
        {
            printf("0\n");
            return 0;
        }
        l=0,r=a[n]-a[1];
        while(r-l>1)
        {
            mid=(l+r)/2;
            if(is_ok(mid)) r=mid;
            else l=mid;
        }
        printf("%I64d\n",r);
    }
    return 0;
}

/**
4
0 1 2 2
1 10 100 1000
*/
