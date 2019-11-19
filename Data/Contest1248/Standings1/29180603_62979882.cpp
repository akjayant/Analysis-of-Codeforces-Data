#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,t1,t2,w1,w2;
long long ans;
int main()
{
	int cas;scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n),t1=t2=0;
		for (int i=1,x;i<=n;i++)
		{
			scanf("%d",&x);
			if (x&1) t1++;
			else t2++;
		}
		scanf("%d",&m),w1=w2=0;
		for (int i=1,x;i<=m;i++)
		{
			scanf("%d",&x);
			if (x&1) w1++;
			else w2++;
		}
		ans=(long long)t1*w1+(long long)t2*w2;
		printf("%lld\n",ans);
	}
	return 0;
}