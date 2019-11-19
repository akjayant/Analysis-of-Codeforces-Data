/* ****mittal**** */
#include<bits/stdc++.h>
#define ll          long long int 
#define pb          push_back
#define endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define repr(i,a,b)   for(ll int i=a;i>=b;i--)
#define lbnd    lower_bound
#define ubnd        upper_bound
#define mp          make_pair
using namespace std;

#define N  100005
ll binpow(ll a,ll b,ll mod)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
ll fac[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
     fac[1]=1;
    fac[0]=1;
    for(int i=1;i<=100002;i++)
    	fac[i]=(fac[i-1]*i)%hell;
//    cin>>TESTS;
    while(TESTS--)
    {
        ll n,m;
        cin>>n>>m;
        ll c=0,d=0;
        for(int i=0;i<=n/2;i++)
        {
        	ll x=fac[n-i];
        	ll y=(fac[n-2*i]*fac[i])%hell;
        	x=(x*(binpow(y,hell-2,hell)))%hell;
        	c=(c+x)%hell;
        }
        c=(c*2)%hell;
        ll ans=0;
        ans+=c;
        c=0;
        for(int i=0;i<=m/2;i++)
        {
        	ll x=fac[m-i];
        	ll y=(fac[m-2*i]*fac[i])%hell;
        	x=(x*(binpow(y,hell-2,hell)))%hell;
        	c=(c+x)%hell;
        }
        ans=(ans+(c*2)%hell)%hell;
        cout<<(ans-2+hell)%hell;
    }
    return 0;
}