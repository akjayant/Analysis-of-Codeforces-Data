#include <cstdio>
#include <cstring>
int a,b,c,n,res=0;
char s[103],p[103];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		res=0;memset(p,0,sizeof(p));
		scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1);//a:r b:p c:s
		for (int i=1;i<=n;i++)
			if (s[i]=='R')
			{
				if (b) --b,p[i]='P',++res;
			}
			else if (s[i]=='P')
			{
				if (c) --c,p[i]='S',res++;
			}
			else 
			{
				if (a) --a,p[i]='R',++res;
			}
		if (res*2<n)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i=1;i<=n;i++)
			if (!p[i])
			{
				if (a) --a,putchar('R');
				else if (b) --b,putchar('P');
				else --c,putchar('S');
			}
			else putchar(p[i]);
		puts("");
	}
	return 0;
}