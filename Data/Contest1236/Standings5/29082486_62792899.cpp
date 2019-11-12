#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll bpow(ll a,ll b,ll m)
{
	a%=m;
	ll res=1;
	while(b>0)
	{
		if(b&1)
			res=res*a%m;
		a=a*a%m;
		b>>=1;
	}
	return res;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll ans=bpow(2,m,mod);
    ans--;
    if(ans<0)
    	ans+=mod;
    ans=bpow(ans,n,mod);
    cout<<ans<<endl;
    return 0;
}