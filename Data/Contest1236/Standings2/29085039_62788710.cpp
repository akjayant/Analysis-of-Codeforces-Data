#include <cstdio>
#include <algorithm>
using namespace std;
int a,b,c;
int main()
{
	int T; scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(b>=c/2+2*a) printf("%d\n",c/2*3+a*3);
		else
			{int ans=min(b,c/2)*3;b-=min(b,c/2),ans+=min(b/2,a)*3,printf("%d\n",ans); }
	}
}