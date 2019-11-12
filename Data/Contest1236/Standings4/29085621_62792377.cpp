#include<bits/stdc++.h>
#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%I64d",&a)
using namespace std;
typedef long long ll;
const int maxn=1e5+50;
const int mod=1e9+7;

ll qk(ll a,ll b,ll p)
{
	ll ans=1%p;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b=b>>1;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	ll a,b;
	cin>>a>>b;
	ll z=qk(2,b,mod)%mod;
	z=(z-1+mod)%mod;
	ll fin=qk(z,a,mod)%mod;
	cout<<fin<<endl;
	return 0;
}
