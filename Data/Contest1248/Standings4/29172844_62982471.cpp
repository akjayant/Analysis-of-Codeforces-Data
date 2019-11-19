#include<cstdio>
int T,n,m,c1,c2;
long long p,ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		c1=c2=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%I64d",&p);
			if(p&1)
				c1++;
			else
				c2++;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%I64d",&p);
			if(p&1)
				ans+=c1;
			else
				ans+=c2;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
