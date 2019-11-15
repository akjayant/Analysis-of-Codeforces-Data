#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

char s[10005],t[10005];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,a,b,c,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n+1;i++) t[i]='\0';
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='R'&&b) t[i]='P',b--,ans++;
			if(s[i]=='P'&&c) t[i]='S',c--,ans++;
			if(s[i]=='S'&&a) t[i]='R',a--,ans++;
		}
		for(int i=1;i<=n;i++) if(t[i]<'A'||t[i]>'Z')
		{
			if(a)
			{
				a--;t[i]='R';continue;
			}
			if(b)
			{
				b--;t[i]='P';continue;
			}
			if(c)
			{
				c--;t[i]='S';continue;
			}
		}
		if(ans*2>=n)
		{
			printf("YES\n");
			printf("%s\n",t+1);
		}
		else printf("NO\n");
	}
}
