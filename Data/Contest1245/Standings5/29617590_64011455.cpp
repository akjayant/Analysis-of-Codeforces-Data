#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
int t;
int n;
int a,b,c;
char s[110][110];
char ans[110][110];
int res1;
int res2;
bool used[110][110];
int main()
{
	scanf("%d",&t);
	for(int o=1;o<=t;o++)
	{
		scanf("%d",&n);
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",s[o]);
		res1=0;
		res2=(n+1)/2;
		int len=strlen(s[o]);
		for(int i=0;i<len;i++)
		{
			if(s[o][i]=='S')
			{
				if(a)
				{
					used[o][i]=true;
					a--;
					ans[o][i]='R';
					res1++;
				}
			}
			if(s[o][i]=='R')
			{
				if(b)
				{
					used[o][i]=true;
					b--;
					ans[o][i]='P';
					res1++;
				}
			}
			if(s[o][i]=='P')
			{
				if(c)
				{
					used[o][i]=true;
					c--;
					ans[o][i]='S';
					res1++;
				}
			}
		}
		if(res1>=res2)
		{
			printf("YES\n");
			for(int i=0;i<len;i++)
			{
				if(used[o][i])
				{
					cout<<ans[o][i];
				}
				else
				{
					if(a)
					{
						a--;
						printf("R");
					}
					else
					{
						if(b)
						{
							b--;
							printf("P");
						}
						else
						{
							if(c)
							{
								c--;
								printf("S");
							}
						}
					}
				} 
			}
			printf("\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
} 