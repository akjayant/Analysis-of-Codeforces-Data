#include <cstdio>
#include <cstring>

const int MAX_N = 105;

int t, n, a, b, c;
char s[MAX_N], k[MAX_N];

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		memset(k, 0x00, sizeof(k)); 
		scanf("%d%d%d%d %s", &n, &a, &b, &c, s);
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == 'R' && b > 0) { --b; ++cnt; k[i] = 'P'; }
			if (s[i] == 'P' && c > 0) { --c; ++cnt; k[i] = 'S'; }
			if (s[i] == 'S' && a > 0) { --a; ++cnt; k[i] = 'R'; }
		}
		for (int i = 0; i < n; ++i)
			if (!k[i])
				if (a) { --a; k[i] = 'R'; }
				else if (b) { --b; k[i] = 'P'; }
				else { --c; k[i] = 'S'; }
		if (cnt * 2 >= n) printf("YES\n%s\n", k);
		else printf("NO\n");
	}
	return 0;
}
