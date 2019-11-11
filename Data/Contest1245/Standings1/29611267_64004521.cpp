#include<bits/stdc++.h>
using namespace std;
int t,n,r,p,s,r1,p1,s1;
char buf[1005],ans[1005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%s",&n,&r,&p,&s,buf+1);
		int cnt=0;
		for(int i=1;i<=n;i++) ans[i]=0;
		for(int i=1;i<=n;i++) if(buf[i]=='R'&&p) ans[i]='P',p--,cnt++;
		for(int i=1;i<=n;i++) if(buf[i]=='S'&&r) ans[i]='R',r--,cnt++;
		for(int i=1;i<=n;i++) if(buf[i]=='P'&&s) ans[i]='S',s--,cnt++;
		for(int i=1;i<=n;i++)
		{
			if(ans[i]) continue;
			if(r) ans[i]='R',r--;
			else if(p) ans[i]='P',p--;
			else ans[i]='S',s--;
		}
		if(cnt>=(n+1)/2)
		{
			puts("YES");
			for(int i=1;i<=n;i++) printf("%c",ans[i]);
			puts("");
		}
		else puts("NO");
	}
	return 0;
}