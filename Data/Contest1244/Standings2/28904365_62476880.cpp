#include <bits/stdc++.h>
using namespace std;
#define llong long long
int n;
llong k;
int a[200200];
llong sum[200200];

bool check(int n,int x)
{
	llong res=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		int p=upper_bound(a+1,a+2+n,a[i]+x)-a;
		llong ta=1ll*(i-1)*a[i]-sum[i-1]+sum[n]-sum[p-1]-1ll*(n-p+1)*(a[i]+x);
		res=min(res,ta);
	}
	for(int i=n;i>=1;i--)
	{
		int p=upper_bound(a,a+1+n,a[i]-x)-a;
		llong ta=1ll*(p-1)*(a[i]-x)-sum[p-1]+sum[n]-sum[i]-1ll*(n-i)*a[i];
		res=min(res,ta);
	}
	return res<=k;
}
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[n+1]=0x7fffffff;
	sort(a+1,a+1+n);
	a[0]=-a[n];
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	sum[n+1]=sum[n];
	int l=0,r=0x3f3f3f3f;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(n,mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
