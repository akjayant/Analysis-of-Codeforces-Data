#include<bits/stdc++.h>
#define ll long long 
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
#define lpri(n) printf("%lld",n)
#define pri(n) printf("%d",n)
#define pln() printf("\n")
#define priln(n) printf("%d\n",n)
#define lpriln(n) printf("%lld\n",n)
#define rep(i,init,n) for(int i=init;i<n;i++)
#define pb push_back     
#define mp make_pair
#define F first
#define S second
#define gcd __gcd
#define inf INT_MAX
#define ninf INT_MIN
using namespace std;
const ll mod=1e9+7;         
const int N=2e5+4;
int main()                  
{
    ll fac[N];
    
    fac[1]=1;fac[2]=2;
    
    rep(i,3,N)
    fac[i]=(fac[i-1]+fac[i-2])%mod;
    
    int n,m;
    
    scn(n);scn(m);
    
    ll ans=(fac[n]+fac[m]-1)%mod;
    
    ans=(ans*2)%mod;
    
    lpri(ans);
}