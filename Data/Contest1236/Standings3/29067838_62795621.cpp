#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
const ll mod=1e9+7;
ll n,m;
ll Pow(ll a,ll b, ll mod)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    //freopen("ce.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<n;++j)
            if(j%2==0) printf("%d ",i+j*n);else printf("%d ",n-i+1+j*n);
        printf("\n");
    }
    return 0;
}
