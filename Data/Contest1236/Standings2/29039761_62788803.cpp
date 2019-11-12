#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pi;
 
ll n,m,mod=1e9+7;

ll pw(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a,ret%=mod;
		b>>=1,a=a*a,a%=mod;
	}
	ret=ret%mod;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	ll a=pw(2,m)-1;
	a=a%mod;
	cout<<pw(a,n)%mod;
	return 0;
}