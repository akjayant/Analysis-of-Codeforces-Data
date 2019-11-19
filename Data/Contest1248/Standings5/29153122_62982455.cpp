#include <bits/stdc++.h>
using namespace std;
long long t,n,x,a[2],b[2];
int main()
{
	scanf("%lld",&t);
	while (t--)
	{
		a[0]=a[1]=b[0]=b[1]=0;
		scanf("%lld",&n);
		for (int i=1;i<=n;i++)
		scanf("%lld",&x),a[x%2]++;
		scanf("%lld",&n);
		for (int i=1;i<=n;i++)
		scanf("%lld",&x),b[x%2]++;
		printf("%lld\n",a[1]*b[1]+a[0]*b[0]);
	}
	return 0;
}
