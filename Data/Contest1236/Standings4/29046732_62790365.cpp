#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n;
const int mod=1000000007;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res%mod;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",qpow(qpow(2,m)-1,n));
	return 0;
 } 