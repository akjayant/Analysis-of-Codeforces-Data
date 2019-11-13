#include<bits/stdc++.h>
#define FOR(i, x, y) for(int i = (x), i##END = (y); i <= i##END; ++i)
#define DOR(i, x, y) for(int i = (x), i##END = (y); i >= i##END; --i)
template<typename T, typename _T> inline bool chk_min(T &x, const _T y) {return y < x ? x = y, 1 : 0;}
template<typename T, typename _T> inline bool chk_max(T &x, const _T y) {return x < y ? x = y, 1 : 0;}
typedef long long ll;
int dp[105][105][105];
char las[105][105][105];
char str[105];
int T;

int mp[200][200];

void recur(int a, int b, int c)
{
	if(a + b + c == 0) return;
	if(las[a][b][c] == 'R') recur(a - 1, b, c);
	if(las[a][b][c] == 'P') recur(a, b - 1 , c);
	if(las[a][b][c] == 'S') recur(a, b, c - 1);
	putchar(las[a][b][c]);
}

int main()
{
	mp['P']['R'] = 1;
	mp['S']['P'] = 1;
	mp['R']['S'] = 1;
	scanf("%d", &T);
	while(T--)
	{
		int n, a, b, c;
		scanf("%d%d%d%d%s", &n, &a, &b, &c, str + 1);
		FOR(i, 0, a) FOR(j, 0, b) FOR(k, 0, c) dp[i][j][k] = -1e9;
		dp[0][0][0] = 0;
		FOR(i, 0, a) FOR(j, 0, b) FOR(k, 0, c)
		{
			int nx = i + j + k + 1;
			if(i < a)
			{
				if(chk_max(dp[i + 1][j][k], dp[i][j][k] + mp['R'][str[nx]]))
					las[i + 1][j][k] = 'R';
			}
			if(j < b)
			{
				if(chk_max(dp[i][j + 1][k], dp[i][j][k] + mp['P'][str[nx]]))
					las[i][j + 1][k] = 'P';
			}
			if(k < c)
			{
				if(chk_max(dp[i][j][k + 1], dp[i][j][k] + mp['S'][str[nx]]))
					las[i][j][k + 1] = 'S';
			}
		}
		if(dp[a][b][c] >= (n + 1) / 2)
		{
			puts("YES");
			recur(a, b, c);
			puts("");
		}
		else puts("NO");
		
	}
	return 0;
}
