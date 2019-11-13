#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
inline ll quickpow(ll base,ll ind)
{
	ll ans=1;
	while(ind>0)
	{
		if(ind&1)ans=ans*base%MOD;
		ind>>=1;
		base=base*base%MOD;
	}
	return ans;
}
int main()
{
	ll n,m;
	cin>>n>>m;
	ll x=quickpow(2ll,m);
	x=(x+MOD-1)%MOD;
//	cout<<x<<endl;
	x=quickpow(x,n);
	cout<<x<<endl;
	return 0;
}
