#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rint register int
using namespace std;
typedef long long ll;
int n;
ll a[100010];
int main()
{
	scanf("%d",&n);
	for(rint i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	ll sum1=0,sum2=0;
	for(rint i=1;i<=n/2;++i)
		sum1+=a[i];
	for(rint i=n/2+1;i<=n;++i)	
		sum2+=a[i];
	printf("%lld",sum1*sum1+sum2*sum2);
	return 0;
}

