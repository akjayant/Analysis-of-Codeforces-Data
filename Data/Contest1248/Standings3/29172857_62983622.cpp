#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	int i,n;
	long long ans=0,s1=0,s2=0;
	scanf("%d",&n);
	for(i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(i=1; i<=n/2; i++) s1+=a[i];
	for(i=(n/2)+1; i<=n; i++) s2+=a[i];
	ans=1ll*s1*s1+1ll*s2*s2;
	printf("%lld",ans);
	return 0;
}