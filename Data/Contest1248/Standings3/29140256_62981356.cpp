#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;

int n,a[maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int n1=n/2;
	ll x=0,y=0;
	for(int i=1;i<=n1;i++)x+=a[i];
	for(int i=n1+1;i<=n;i++)y+=a[i];
	ll ans=x*x+y*y;
	printf("%lld\n",ans);
	return 0;
}