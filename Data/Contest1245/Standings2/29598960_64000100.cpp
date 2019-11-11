#include <bits/stdc++.h>
using namespace std;
int main()
{
	int _,n,a,b,c;scanf("%d",&_);char s[111],ans[111];
	while(_--)
	{
		memset(ans,0,sizeof(ans));
		scanf("%d%d%d%d%s",&n,&a,&b,&c,s);
		int ss=0;
		for(int i=0;i<n;i++)
			if(s[i]=='R')
			{
				if(b)
					ans[i]='P',--b,++ss;
			}
			else if(s[i]=='P')
			{
				if(c)
					ans[i]='S',--c,++ss;
			}
			else
			{
				if(a)
					ans[i]='R',--a,++ss;
			}
		if(ss>=(n+1)/2)
		{
			puts("YES");
			for(int i=0;i<n;i++)
				if(!ans[i])
				{
					if(a)
						ans[i]='R',--a;
					else if(b)
						ans[i]='P',--b;
					else
						ans[i]='S',--c;
				}
			puts(ans);
		}
		else
			puts("NO");
	}
	return 0;
}