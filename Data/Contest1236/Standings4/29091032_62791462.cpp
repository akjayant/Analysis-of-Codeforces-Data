#include <bits/stdc++.h>
using namespace std;

#define ll long long 
ll exp(ll x,ll y,ll mod)
{
	ll res=1;
	while(y>0)
	{
		if(y%2==1)
		res=(res%mod*x%mod)%mod;
		y=y/2;
	x=(x%mod*x%mod)%mod;
	}
	return res;
	
}
int main()
{
	ll n,m;
	cin>>n>>m;
	ll mod=1000000007;
	ll ans=0;
	ans=exp(2,m,mod)-1;
	ans=exp(ans,n,mod);
	cout<<ans;
	return 0;
}
