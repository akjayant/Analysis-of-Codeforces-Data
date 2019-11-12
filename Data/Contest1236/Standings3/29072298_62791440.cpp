#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
#define mod 1000000007
ll power(ll n,ll p)
{
    if(p==0) return 1;
    ll P=power(n,p/2);
    if(p%2==0) return ((((P%mod)*(P%mod))%mod)*(1%mod))%mod;
    if(p%2==1) return ((((P%mod)*(P%mod))%mod)*(n%mod))%mod;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    cout<<power((power(2,m)-1+mod)%mod,n);
}