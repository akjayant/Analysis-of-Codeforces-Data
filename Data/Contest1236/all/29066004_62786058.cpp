#include<bits/stdc++.h>
using namespace std;
#define maxn 300005
typedef long long ll;
char s[maxn];
ll dp[maxn],pre[maxn],sum[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,ans=0;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=0;i<=a&&2*i<=b;i++)
		{
			int now=3*i+min(b-2*i,c/2)*3;
			ans=max(ans,now);
		}
		printf("%d\n",ans);
	}
    return 0;
}