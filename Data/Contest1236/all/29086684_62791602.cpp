#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll bigmod(ll n,ll p)
{
    ll temp;
    if(p==0)
       return 1;
    else if(p==1)
       return n%mod;
    else if(p&1){
       temp=bigmod(n,p/2);
       return (((temp*temp)%mod)*(n%mod))%mod;
    }
    else {
       temp=bigmod(n,p/2);
       return (temp*temp)%mod;
    }
}
int main()
{
    ll n,m;
    ll p,q;
    scanf("%lld %lld",&n,&m);
    p=bigmod(2,m);
    p=(mod+p-1)%mod;
    q=bigmod(p,n);
    printf("%lld\n",q);
}
