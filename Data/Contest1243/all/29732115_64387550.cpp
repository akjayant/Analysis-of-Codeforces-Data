#include<bits/stdc++.h>

using namespace std;
const int maxnn=1e4+7;
typedef long long ll;
ll a[maxnn];
int main()
{
    ll n;
    scanf("%lld",&n);
    int cnt=0;
    for(ll i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            a[cnt++]=i;
            if(n%i!=i)
                a[cnt++]=n/i;
        }
    }
    a[cnt++]=n;
    sort(a,a+cnt);
    ll ans=a[0];
    for(int i=cnt-1;i>=1;i--)
    {
        ans=__gcd(ans,a[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
