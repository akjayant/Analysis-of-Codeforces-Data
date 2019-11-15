#include<cstdio>
#include<algorithm>
using namespace std;
int T,a,b,c,ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		ans=0;
		for(int i=0;i<=b;i++)
			ans=max(ans,min(a,i/2)+min(b-i,c/2));
		printf("%d",ans*3);
		if(T)
			printf("\n");
	}
} 