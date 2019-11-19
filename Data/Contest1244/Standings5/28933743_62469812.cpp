#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1006;
char s[maxn];
int n;
int main()
{
	int _;
	for(scanf("%d",&_);_;_--)
	{
		scanf("%d%s",&n,s+1);
		int ans=n;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				int mx=max(2*i,2*(n-i+1));
				ans=max(ans,mx);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
