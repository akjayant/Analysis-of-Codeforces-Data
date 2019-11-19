#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long lint;
lint c[2][2];
lint ans;
int xi,n,m,t;
void memclr()
{
	memset(c,0,sizeof(c));
	ans=0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memclr();
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&xi),c[0][xi&1]++;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&xi),c[1][xi&1]++;
		ans=c[0][0]*c[1][0]+c[0][1]*c[1][1];
		printf("%I64d\n",ans);
	}
	return 0;
}