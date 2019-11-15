#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 100002
int T,a,b,c;
char s[N],ans[N];
bool fk[N];
int n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&a,&b,&c);
		scanf("%s",s+1);
		memset(fk,0,sizeof(fk));
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='R'&&b)
			{
				b--;
				ans[i]='P';
				cnt++;
				fk[i]=1;
			}
			else if(s[i]=='P'&&c)
			{
				c--;ans[i]='S';
				cnt++;fk[i]=1;
			}
			else if(s[i]=='S'&&a)
			{
				a--;ans[i]='R';
				cnt++;fk[i]=1;
			}
		}
		if(cnt>=(n+1)/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(!fk[i])
				{
					if(a)ans[i]='R',a--;
					else if(b)ans[i]='P',b--;
					else ans[i]='S',c--;
				}
			}
			puts("YES");
			for(int i=1;i<=n;i++)putchar(ans[i]);puts("");
		}
		else puts("NO");
	}
}

