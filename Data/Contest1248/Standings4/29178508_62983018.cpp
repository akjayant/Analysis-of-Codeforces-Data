#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long n,a[maxn],n1,n2,ans1,ans2;
int main()
{
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    n1=n/2;
    n2=n-n1;
    ans1=ans2=0;
    for (int i=1;i<=n1;++i) ans1+=a[i];
    for (int i=n1+1;i<=n;++i) ans2+=a[i];
    long long ans=ans1*ans1+ans2*ans2;
    printf("%lld\n",ans);
    return 0;
}
