#include<cstdio>
#include<cmath>
 #include<bits/stdc++.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 0x3fffffff
using namespace std;
int n;
char s[1000],ss[1000];
int main()
{
	int t,a,b,c,x,y,z;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",s+1);
		x=0;y=0;z=0;
		for (int i=1;i<=n;i++) if (s[i]=='R') x++;
		else if (s[i]=='P') y++;
		else if (s[i]=='S') z++;
		int ans=0;
		ans=min(a,z)+min(b,x)+min(c,y);
		//printf("%d\n",ans);
		if (ans>=(n+1)/2) 
		{
			printf("YES\n");
			for (int i=1;i<=n;i++) 
			{
				if (s[i]=='S' && z && a)
				{
					ss[i]='R';
					z--;
					a--;
				}
				else
				if (s[i]=='R' && b && x)
				{
					b--;
					x--;
					ss[i]='P';
				}
				else 
				if (s[i]=='P' && c && y)
				{
					y--;
					c--;
					ss[i]='S';
				}
				else ss[i]='a';
			}
			for (int i=1;i<=n;i++) if (ss[i]=='a')
			{
				
				if (a) a--,ss[i]='R';
				else if (b) b--,ss[i]='P';
				else if (c) c--,ss[i]='S';
			}
			for (int i=1;i<=n;i++) printf("%c",ss[i]);
			printf("\n");
		}
		else puts("NO");
	}
}