#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define rep(i,a) for(ll i=0;i<a;i++)
#define repe(i,a,b) for(ll i=a;i<b;i++)
#define bac(i,a) for(ll i=a;i>=0;i--)
#define bace(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define in insert
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vpii;
typedef pair<ll,ll> pi;
#define all(c) c.begin(),c.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define setbitc(x) __builtin_popcount(x)
#define init(x,a) memset(x,a,sizeof(x))
#define inf 1000000000000000000  
#define mod 1000000007
#define M 998244353
#define N 500010
#define PI 3.14159265358979323846  

ll modex(ll x,ll n)
{
	if(n==0)
		return 1;
    else if(!(n&1))        
    	return modex((x*x)%mod,n/2);
    else                             
    	return (x*modex((x*x)%mod,(n-1)/2))%mod;
 
}
ll modinv(ll n) 
{ 
	return modex(n,mod-2); 
}
//Variables start
ll dp[100010][2][3];
//Variables end
ll rec(ll n,ll i,ll x,ll f)
{
    if(i==n) return 1;
    if(dp[i][f][x]!=-1) return dp[i][f][x]%mod;
    ll temp=0;
    x++;
    if(!f)
    {
        if(x==2) temp=(temp+rec(n,i+1,0,1))%mod;
        else temp=(temp+(rec(n,i+1,x,0)+rec(n,i+1,0,1))%mod)%mod;
        dp[i][f][x-1]=temp%mod;
    }
    else
    {
        if(x==2) temp=(temp+rec(n,i+1,0,0))%mod;
        else temp=(temp+(rec(n,i+1,x,1)+rec(n,i+1,0,0))%mod)%mod;
        dp[i][f][x-1]=temp%mod;
    }
    return dp[i][f][x-1]%mod;
}

void solve()
{
    ll n,m,a,b;
    cin>>n>>m;
    init(dp,-1);
    a=rec(m,1,0,0)+rec(m,1,0,1);
    init(dp,-1);
    b=rec(n,1,0,0)+rec(n,1,0,1);
    cout<<((a+b)%mod-2+mod)%mod<<"\n";
}

int main()
{
    fastio;
    ll t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
    
}