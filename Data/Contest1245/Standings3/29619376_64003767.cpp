#include <cstdio>
#include <cstring>

using namespace std;

char s[105], ans[105];

int main (void)
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, a, b, c, w = 0;
		scanf("%d", &n);
		scanf("%d %d %d", &a, &b, &c);
		scanf("%s", s+1);
		memset(ans, 0, sizeof(ans));
		for(register int i=1; i<=n; ++i)
			if(s[i] == 'R' && b > 0)
			{
				++ w;
				ans[i] = 'P';
				-- b;
			}
			else if(s[i] == 'P' && c > 0)
			{
				-- c;
				ans[i] = 'S';
				++ w;
			}
			else if(s[i] == 'S' && a > 0)
			{
				-- a;
				ans[i] = 'R';
				++ w;
			}
		if(w >= (n+1)/2)
		{
			printf("YES\n");
			for(register int i=1; i<=n; ++i)
				if(ans[i]) printf("%c", ans[i]);
				else if(a) { printf("R"); -- a; }
				else if(b) { printf("P"); -- b; }
				else { printf("S"); -- c; }
			printf("\n");
		}			
		else
			printf("NO\n");
	}

	return 0;
}
