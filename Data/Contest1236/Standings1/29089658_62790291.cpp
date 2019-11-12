#include<cstdio>
#include<algorithm>
using namespace std;
int t,i,ans=0,a,b,c;
int main()
{
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		ans=0;
		while(b>=1&&c>=2)
		{
			ans+=3;
			c-=2;b--;
		}
		while(a>=1&&b>=2)
		{
			ans+=3;
			b-=2;a--;
		}
		printf("%d\n",ans);
	}
	return 0;	
} 