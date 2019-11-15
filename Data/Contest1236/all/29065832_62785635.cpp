#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll n, m, k, ans, mod=1e9+7;
ll pw(ll a, ll b)
{
	ll ret=1;
	a%=mod;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, temp=0;
	cin>>n>>m;
	cout<<pw(pw(2, m)-1+mod, n);
}