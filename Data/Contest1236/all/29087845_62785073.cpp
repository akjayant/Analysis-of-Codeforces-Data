#include <bits/stdc++.h>
using namespace std;

int T,a,b,c;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&a,&b,&c);
		int ans=0;
		while(b>=1&&c>1)
		{
			ans+=3;
			c-=2;
			b--;
		}
		while(b>1&&a>=1)
		{
			ans+=3;
			b-=2;
			a--;
		}
		printf("%d\n",ans);
	}
	return 0;
}