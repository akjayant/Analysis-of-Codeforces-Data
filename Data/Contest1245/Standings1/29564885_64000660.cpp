#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset((a), 0, sizeof(a))
#define str(a) strlen(a)
#define pii pair<int, int>
typedef long long LL;

const int maxn = 1010;

int T, n, a, b, c;
char s[maxn], ans[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &T);
	while ( T -- )
	{
		scanf("%d%d%d%d", &n, &a, &b, &c);
		scanf("%s", s + 1); int sum = 0;
		mem(ans);
		REP(i, 1, n)
		{
			if ( s[i] == 'R' && b ) { -- b; ans[i] = 'P'; ++ sum; }
			if ( s[i] == 'P' && c ) { -- c; ans[i] = 'S'; ++ sum; }
			if ( s[i] == 'S' && a ) { -- a; ans[i] = 'R'; ++ sum; }
		}
		int x = (n - 1) / 2 + 1;
		if ( sum < x ) puts("NO");
		else
		{
			puts("YES");
			REP(i, 1, n)
			{
				if ( ans[i] ) continue ;
				if ( a ) { -- a; ans[i] = 'R'; }
				else if ( b ) { -- b; ans[i] = 'P'; }
				else if ( c ) { - c; ans[i] = 'S'; }
			}
			printf("%s\n", ans + 1);
		}
	}
	return 0;
}
