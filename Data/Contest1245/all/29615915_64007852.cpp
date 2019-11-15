#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
char s[105],t[105];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",s+1);
		int ans=0;
		memset(t,0,sizeof(t));
		//rsp
		for (int i=1;i<=n;i++)
		{
			if (s[i]=='R'&&b) t[i]='P',--b,++ans;
			if (s[i]=='S'&&a) t[i]='R',--a,++ans;
			if (s[i]=='P'&&c) t[i]='S',--c,++ans;
		}
		for (int i=1;i<=n;i++)
			if (!t[i])
			{
				if (a) --a,t[i]='R';
				else 
					if (b) --b,t[i]='P';
					else
						if (c) --c,t[i]='S';
			}
		if (ans*2>=n&&a==0&&b==0&&c==0)
		{
			puts("YES");
			puts(t+1);
		}
		else puts("NO");
	}
	return 0;
}
