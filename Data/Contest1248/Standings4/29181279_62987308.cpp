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
	ll n;
	scanf("%lld",&n);
	ll s1=0,s2=0;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s1+=a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n/2;i++)
	{
		s2+=a[i];
	}
	ll s3=s1-s2;
	printf("%lld\n",s2*s2+s3*s3);
}