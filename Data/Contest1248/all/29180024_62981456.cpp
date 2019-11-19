#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+7;
int n;
ll a[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    ll t1=0,t2=0;
    for(int i=1;i<=n/2;i++)
        t1+=a[i];
    for(int i=n/2+1;i<=n;i++)
        t2+=a[i];
    printf("%lld\n",t1*t1+t2*t2);
}

