#include<bits/stdc++.h>
using namespace std;
long long sum1,sum2,ans;
int T,n,m;
int p,q;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		sum1=0; sum2=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&p);
			if (p%2==1) sum1++;
			else sum2++;
		}
		ans=0;
		scanf("%d",&m);
		for (int i=1;i<=m;i++)
		{
			scanf("%d",&q);
			if (q%2==1) ans+=sum1;
			else ans+=sum2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}