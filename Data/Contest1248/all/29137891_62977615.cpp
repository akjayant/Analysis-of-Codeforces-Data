#include<bits/stdc++.h>
using namespace std;
char s[100001];
int a[100001];
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,x;
		long long ans=0;
		a[0]=a[1]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&x),a[x%2]++;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&x),ans+=a[x%2];
		printf("%I64d\n",ans);
	}
	return 0;
}