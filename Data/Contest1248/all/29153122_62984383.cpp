#include <bits/stdc++.h>
using namespace std;
long long n,a[200000],y,x;
int main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n/2;i++)
	y+=a[i];
	for (int i=n/2+1;i<=n;i++)
	x+=a[i];
	printf("%lld",x*x+y*y);
	return 0;
}
