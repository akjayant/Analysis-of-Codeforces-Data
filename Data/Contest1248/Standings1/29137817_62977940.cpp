#include<cstdio>
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n,m,cnt1=0,cnt2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			if (x&1) cnt1++;	
		} 
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			int x;
			scanf("%d",&x);
			if (x&1) cnt2++;
		}
		printf("%lld\n",1LL*cnt1*cnt2+1LL*(n-cnt1)*(m-cnt2));
	}
	return 0;	
} 