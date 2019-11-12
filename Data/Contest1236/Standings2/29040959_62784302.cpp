#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int ans=min(c/2,b)*3;
		b-=min(c/2,b);
		ans+=min(a,b/2)*3;
		printf("%d\n",ans);
	}
	return 0;
}
