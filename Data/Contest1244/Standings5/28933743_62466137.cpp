#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,c,d,k;
int main()
{
	int _;
	for(scanf("%d",&_);_;_--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int x=a/c+(a%c!=0);
		int y=b/d+(b%d!=0);
		if(x+y<=k)printf("%d %d\n",x,y);
		else puts("-1");
	}
	return 0;
}
