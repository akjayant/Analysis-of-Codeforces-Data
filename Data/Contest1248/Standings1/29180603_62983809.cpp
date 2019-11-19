#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n;
long long a[100005],ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) a[i]+=a[i-1];
	ans=a[n/2]*a[n/2]+(a[n]-a[n/2])*(a[n]-a[n/2]);
	printf("%lld\n",ans);
	return 0;
}