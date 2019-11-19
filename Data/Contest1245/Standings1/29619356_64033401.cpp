#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[12][12] , b[12][12];
double dp[12][12][2] , g , h;
struct mmp{
	int x , y;
}p[110];

int main()
{
	int i , j;
	for (i = 1 ; i <= 10 ; i++)
		for (j = 1 ; j <= 10 ; j++)
			cin >> a[i][j];
	for (i = 1 ; i <= 10 ; i++)
		if (i%2)
		{
			for (j = 1 ; j <= 10 ; j++)
				p[++n] = {i,j};
		}
		else
		{
			for (j = 10 ; j >= 1 ; j--)
				p[++n] = {i,j};
		}
	for (i = 2 ; i <= n ; i++)
	{
		g = h = 0;
		for (j = 1 ; j <= 6 ; j++)
			if (i-j >= 1)
			{
				g++;
				h += dp[p[i-j].x][p[i-j].y][1];
			}
		int x = p[i].x;
		int y = p[i].y;
		dp[x][y][0] = dp[x][y][1] = (h+6.0)/g;
		if (a[x][y]) dp[x][y][1] = min(dp[x][y][1],dp[x-a[x][y]][y][0]);
	}
	printf("%.8lf\n",dp[10][1][1]);
	return 0;
}