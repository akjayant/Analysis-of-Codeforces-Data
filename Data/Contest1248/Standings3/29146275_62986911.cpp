#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3
const int maxn=100005;
ll a[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0,sum1=0;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n/2;i++) sum1+=a[i];
    ll sum2=sum-sum1;
    ll ans=sum1*sum1+sum2*sum2;
    printf("%lld\n",ans);
    return 0;
}
