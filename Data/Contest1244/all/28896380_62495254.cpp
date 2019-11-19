#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long sl[N];
long long sr[N];
long long a[N];
int main()
{
    long long n,k;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    long long l = 0,r = a[n]-a[1];
    for(long long i=1;i<=n;i++)   sl[i] = a[i]+sl[i-1];
    for(long long i=n;i>=1;i--)   sr[i] = a[i]+sr[i+1];
    while(l<r)
    {
        long long mid = (l+r) >> 1,ch = 0;
        for(long long i=1;i<=n;i++)
        {
            long long idx = upper_bound(a+1,a+n+1,a[i]+mid)-a;
            long long suml = a[i]*i-sl[i];
            long long sumr = sr[idx]-(n-idx+1)*(a[i]+mid);
            if(suml+sumr<=k)    {ch=1;break;}

        }
        for(long long i=n;i>=1;i--)
        {
            long long idx = upper_bound(a+1,a+n+1,a[i]-mid)-a-1;
            long long suml = (a[i]-mid)*idx-sl[idx];
            long long sumr = sr[i]-a[i]*(n-i+1);
            if(suml+sumr<=k) {ch=1;break;}
        }
        if(ch)  r=mid;
        else    l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}
