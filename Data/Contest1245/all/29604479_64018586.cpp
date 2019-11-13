#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T;
char str[100000];
char sa[100000];
bool vis[100000];
int main()
{
	scanf("%d", &T);
	while(T --)
	{
		int n;
		scanf("%d", &n);
		int r, s, p;
		scanf("%d%d%d", &r, &p, &s);
		scanf("%s", str + 1);
		int len = strlen(str + 1);
		int ans = 0;
		memset(vis, 0, sizeof vis);
		for(int i = 1 ; i <= len ; i ++)
		{
			if(str[i] == 'P' && s > 0)
				s --, vis[i] = 1, ans ++;
			if(str[i] == 'R' && p > 0) 
				p --, vis[i] = 1, ans ++;
			if(str[i] == 'S' && r > 0)
				r --, vis[i] = 1, ans ++;
		}
		if(ans < (n + 1) / 2)
		{
			printf("NO\n");
			continue ;
		}
		printf("YES\n");
		for(int i = 1 ; i <= len ; i ++)
		{
			if(str[i] == 'P' && vis[i])
				printf("S");
			if(str[i] == 'P' && !vis[i])
			{
				if(r > 0)
					printf("R"), r --;
				else
					printf("P") , p --;
			}
			if(str[i] == 'R' && vis[i])
				printf("P");
			if(str[i] == 'R' && !vis[i])
			{
				if(r > 0)
					printf("R"), r --;
				else
					printf("S"), s --;
			}
			if(str[i] == 'S' && vis[i])
				printf("R");
			if(str[i] == 'S'&& !vis[i])
			{
				if(s > 0)
					printf("S"), s --;
				else
					printf("P"), p --;
			}
		}
		printf("\n");
	}
	return 0;
}
