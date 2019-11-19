#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d",&n);
		int cnt1=0,cnt2=0;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			if(x>=0)
			{
				if(x%2)
					cnt1++;
				else
					cnt2++;
			}
			else
			{
				if((-x)%2)
					cnt1++;
				else
					cnt2++;
			}
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			int x;
			scanf("%d",&x);
			if(x>0)
			{
				if(x%2)
					ans+=cnt1;
				else
					ans+=cnt2;
			}
			else
			{
				if((-x)%2)
					ans+=cnt1;
				else
					ans+=cnt2;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}