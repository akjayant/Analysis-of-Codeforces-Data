#include<bits/stdc++.h>
using namespace std;
long long n;
long long sum1,sum2;
long long a[100010];
int main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	sum1=0; sum2=0;
	for (int i=1;i<=n/2;i++)
		sum1+=a[i];
	for (int i=n/2+1;i<=n;i++)
		sum2+=a[i];
	printf("%lld\n",sum1*sum1+sum2*sum2);
	return 0;
}