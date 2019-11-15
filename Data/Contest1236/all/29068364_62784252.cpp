#include<bits/stdc++.h>
using namespace std;

int T,ans,a,b,c,w;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d%d%d",&a,&b,&c);
		w=min(b,c/2);
		ans=3*w;
		b-=w;
		w=min(a,b/2);
		ans+=3*w;
		printf("%d\n",ans);
	}
	return 0;
}