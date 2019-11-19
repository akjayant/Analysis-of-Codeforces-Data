#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
const ll mod=1e9+7;
ll dp[maxn];
int main()
{
	dp[1]=2;
	dp[2]=4;
	ll n,m;
	scanf("%lld %lld",&n,&m);
	ll maxx=max(n,m);
	for(ll i=3;i<=maxx+10;i++)
	{
		dp[i]=(dp[i-1]+dp[i-2])%mod;
	}
	printf("%lld\n",(dp[n]+dp[m]-2)%mod);
}