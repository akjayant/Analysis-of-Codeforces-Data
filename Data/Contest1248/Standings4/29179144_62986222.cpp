#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005];
int n,m;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    ll l=0,r=0;
    for (int i=1;i<=n/2;i++) l+=a[i];
     for (int i=n/2+1;i<=n;i++) r+=a[i];
    ll ans=l*l+r*r;
    printf("%lld\n",ans);
}
