#include <bits/stdc++.h>

const int maxn=1e4+5;

int a[maxn],n;
int main()
{
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int t;scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);int ans=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		std::sort(a+1,a+n+1);
		for(int i=n;i>=1;i--)
		{
			if(a[i]>=n-i+1) ans=n-i+1;
			else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}