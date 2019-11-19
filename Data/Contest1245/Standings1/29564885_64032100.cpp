#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset((a), 0, sizeof(a))
#define str(a) strlen(a)
#define pii pair<int, int>
typedef long long LL;

const int maxn = 20;

int a[maxn][maxn], n = 10;
long double f[maxn][maxn];

inline void Solve(int x, int y, int &u, int &v, int k)
{
	while ( k -- )
	{
		if ( x & 1 )
		{
			if ( y == 1 ) { -- x; y = 1; }
			else -- y;
		}
		else
		{
			if ( y == n ) { -- x; y = n; }
			else ++ y;
		}
	}
	u = x; v = y;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	REP(i, 1, n) REP(j, 1, n) scanf("%d", &a[i][j]);
	REP(i, 2, 7) f[1][i] = 6;
	REP(i, 1, n)
	{
		if ( i & 1 )
			REP(j, 1, n)
			{
				if ( i == j && i == 1 ) continue ;
				if ( f[i][j] ) continue ;
				int x, y; f[i][j] = 1;
				REP(k, 1, 6)
				{
					Solve(i, j, x, y, k);
					if ( a[x][y] ) f[i][j] += 1.0 / 6 * min(f[x][y], f[x - a[x][y]][y]);
					else f[i][j] += 1.0 / 6 * f[x][y];
				}
			}
		else for ( int j = n; j >= 1; -- j )
		{
			int x, y; f[i][j] = 1;
			REP(k, 1, 6)
			{
				Solve(i, j, x, y, k);
				if ( a[x][y] ) f[i][j] += 1.0 / 6 * min(f[x][y], f[x - a[x][y]][y]);
				else f[i][j] += 1.0 / 6 * f[x][y];
			}
		}
	}
	printf("%.7Lf\n", f[n][1]);
	return 0;
}
