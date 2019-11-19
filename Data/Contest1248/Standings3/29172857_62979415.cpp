#include <bits/stdc++.h>
using namespace std;
int a[1000010],h1[2],h2[2],b[10000010];
int main()
{
	int n,T,i,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		h1[0]=h1[1]=h2[0]=h2[1]=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]),h1[a[i]%2]++;
		scanf("%d",&m);
		for(i=1;i<=m;i++) scanf("%d",&b[i]),h2[b[i]%2]++;
		long long ans=0;
		ans=1ll*h1[0]*h2[0]+1ll*h2[1]*h1[1];
		printf("%lld\n",ans);
	}
	return 0;
}