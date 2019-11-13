#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e2 + 5;

int n,a,b,c,t,cnt;
int ans[N];
char s[N];

int main()
{
	//freopen("in","r",stdin);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",s + 1);
		cnt = 0;
		memset(ans,0,sizeof(ans));
		for (int i = 1 ; i <= n ; i++)
		{
			if (s[i] == 'R') if (b) b--,cnt++,ans[i] = 1;
			if (s[i] == 'P') if (c) c--,cnt++,ans[i] = 2;
			if (s[i] == 'S') if (a) a--,cnt++,ans[i] = 3;
		}
		for (int i = 1 ; i <= n ; i++) 
			if (!ans[i]) 
			{
				if (a) ans[i] = 3,a--;
				else if (b) ans[i] = 1,b--;
				else if (c) ans[i] = 2,c--;
			}
		if (cnt >= (n + 1) / 2)
		{
			printf("YES\n");
			for (int i = 1 ; i <= n ; i++)
			{
				if (ans[i] == 1) printf("P");
				if (ans[i] == 2) printf("S");
				if (ans[i] == 3) printf("R");
			}
			printf("\n");
		}
		else printf("NO\n");
	}
	return 0;
}
