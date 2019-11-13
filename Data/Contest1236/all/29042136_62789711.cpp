#include<bits/stdc++.h>
using namespace std;
int a,b,c,ans,T;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ans=0;
		scanf("%d %d %d",&a,&b,&c);
		while (b>=1&&c>=2)
		{
			b--; c-=2; ans+=3;
		}
		while (a>=1&&b>=2)
		{
			a--; b-=2; ans+=3;
		}
		printf("%d\n",ans);
	}
}