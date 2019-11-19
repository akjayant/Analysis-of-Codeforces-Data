#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
ll a[maxn],b[maxn];
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n,j1=0,j2=0,o1=0,o2=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]%2)j1++;
			else o1++;
		}
		ll m;
		scanf("%lld",&m);
		for(ll i=1;i<=m;i++)
		{
			scanf("%lld",&b[i]);
			if(b[i]%2)j2++;
			else o2++;
		}
		printf("%lld\n",j1*j2+o1*o2);
	}
}