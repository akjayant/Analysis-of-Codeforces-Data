#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N=200;
char s[N];
char ans[N];
int flag[N];
int T;
int n,m;
int cr,cp,cs;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int minn=(n+1)/2;
		scanf("%d%d%d",&cr,&cp,&cs);
		scanf("%s",s);
		int cnt=0;
		memset(flag,0,sizeof(flag));
		for(int i=0; i<n; i++)
		{
			if(s[i]=='R')
			{
				if(cp)
				{
					cnt++;
					cp--;
					ans[i]='P';
					flag[i]=1;
				}
			}
			else if(s[i]=='S')
			{
				if(cr)
				{
					cnt++;
					cr--;
					ans[i]='R';
					flag[i]=1;
				}
			}
			else
			{
				if(cs)
				{
					cnt++;
					cs--;
					ans[i]='S';
					flag[i]=1;
				}
			}
		}
		if(cnt>=minn)
		{
			printf("YES\n");
			for(int i=0;i<n;i++)
			{
				if(!flag[i])
				{
					if(cr)
					{
						cr--;
						ans[i]='R';
					}
					else if(cs)
					{
						cs--;
						ans[i]='S';
					}
					else if(cp)
					{
						cp--;
						ans[i]='P';
					}
				}
			}
			for(int i=0; i<n; i++)
				printf("%c",ans[i]);
			printf("\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
