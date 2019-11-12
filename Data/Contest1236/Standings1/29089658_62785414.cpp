#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m;
const ll mod=1e9+7;
ll pow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",pow((pow(2LL,m)-1+mod)%mod,n));
	return 0;
}