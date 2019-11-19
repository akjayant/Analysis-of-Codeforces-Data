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
ll n,m;
//Variables end
void solve()
{
    cin>>n;
    ll a[n],sum=0,sum2=0;
    rep(i,n) cin>>a[i],sum+=a[i];
    sort(a,a+n);
    rep(i,n/2) sum2+=a[i];
    cout<<sum2*sum2+(sum-sum2)*(sum-sum2)<<"\n";
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