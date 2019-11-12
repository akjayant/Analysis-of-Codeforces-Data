#include<bits/stdc++.h>
using namespace std;
int t;
int a,b,c;
int ans,xx;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		ans=min(c/2,b);
		b-=ans;
		ans*=3;
		xx=min(b/2,a);
		ans+=xx*3;
		printf("%d\n",ans);
	}
	return 0;
}