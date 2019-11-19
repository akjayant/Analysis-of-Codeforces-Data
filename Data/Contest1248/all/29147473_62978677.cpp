#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 1000005
int a[N];
bool f[N];
int n,m;
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int t1=0,t2=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			if(x%2==0)
				t1++;
			else
				t2++;
		}
		long long ans=0;
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			int x;
			scanf("%d",&x);
			if(x%2==0)
				ans+=t1;
			else
				ans+=t2;
		}
		printf("%lld\n",ans);
	}
}