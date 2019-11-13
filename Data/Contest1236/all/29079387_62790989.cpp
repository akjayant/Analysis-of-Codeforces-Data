#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#define pb push_back
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define dd(x) cout<<#x<<" = "<<x<<","
#define de(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
typedef long long ll;

const ll mod=1e9+7;

ll qpow(ll a,ll n)
{
	ll re=1;
	while(n>0)
	{
		if(n&1)
		{
			re*=a;
			re%=mod;
		}
		a*=a;
		a%=mod;
		n>>=1;
	}
	return re;
}
int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll x=qpow(2ll,m);
	x--;
	x+=mod;
	x%=mod;
	ll ans=qpow(x,n);
	printf("%lld",ans);
}
