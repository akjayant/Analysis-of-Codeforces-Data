#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,c;
char s[105],Ans[105];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&a,&b,&c);
		scanf("%s",s+1);
		memset(Ans,0,sizeof(Ans));
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='R'&&b>0)Ans[i]='P',b--,ans++;
			if(s[i]=='P'&&c>0)Ans[i]='S',c--,ans++;
			if(s[i]=='S'&&a>0)Ans[i]='R',a--,ans++;
		}
		if(ans>=(n+1)/2)
		{
			puts("YES");
			for(int i=1;i<=n;++i)if(!Ans[i])
			{
				if(a)Ans[i]='R',a--;
				else if(b)Ans[i]='P',b--;
				else Ans[i]='S',c--;
			}
			printf("%s\n",Ans+1);
		}
		else puts("NO");
	}
}