#include<bits/stdc++.h>
using namespace std;


int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int lkj,a,b,c,ans;
	scanf("%d",&lkj);
	while(lkj)
	{
		ans=0;scanf("%d%d%d",&a,&b,&c);
		ans=ans+3*min(b,c/2);
		b=b-min(b,c/2);
		ans=ans+3*min(a,b/2);
		printf("%d\n",ans);
		lkj--;
	}
	return 0;
}
