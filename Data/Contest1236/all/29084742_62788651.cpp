#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll MOD=1e9+7;
ll qpow(ll x,ll y,ll mod)
{
	ll temp=x;
	ll ans=1;
	while(y){
		if(y&1) ans=(ans*temp) % mod;
		temp=(temp*temp)%mod;
		y>>=1;
	}
	return ans;
}
int main()
{
	ll n,m;
	cin>>n>>m;
	ll temp=qpow(2,m,MOD)-1;
	ll ans=qpow(temp,n,MOD);
	cout<<(ans+MOD)%MOD<<endl;
	return 0;
}