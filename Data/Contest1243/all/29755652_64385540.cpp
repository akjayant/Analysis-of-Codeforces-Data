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
const int N=1e5+4;
int main()                  
{
    ll n;
    
    lscn(n);
    
    ll ans=-1,val=0;
    
    for(ll i=2;i*i<=n;i++)
    if(n%i==0)
    {
        ll here=n/i;
        
        val=gcd(val,here);
        
        val=gcd(val,i);
    }
    
    val=gcd(val,n);
    
    lpri(val);
}