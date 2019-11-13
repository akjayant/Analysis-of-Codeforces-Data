#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+10;
//int a[maxn];
ll mod=1e9+7;
ll qpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1)
            ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a,b;
    while(n--)
    {
        scanf("%d%d",&a,&b);
        if(__gcd(a,b)==1)
            printf("Finite\n");
        else
            printf("Infinite\n");
    }

    return 0;
}