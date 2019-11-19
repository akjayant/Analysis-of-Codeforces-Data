#include<bits/stdc++.h>

using namespace std;


int mat[10][10];
int vis[10][10];
double dp[10][10];

pair<int, int> next(int x, int y, int inc)
{
	int x2 = x, y2 = y;
	if((x2&1) == 0)
	{
		y2 -= inc;
		if(y2 < 0)
		{
			y2 = -(y2+1);
			x2--;
		}
	}
	else
	{
		y2 += inc;
		if(y2 >= 10)
		{
			y2 = 19-y2;
			x2--;
		}
	}
	if(x2 < 0)
		return {x, y};
	else
		return {x2, y2};
}

//int flag;

double solve(int x, int y)
{
	//printf("%d %d\n", x, y);
	if(x == 0 && y == 0)
		return 0;
	if(vis[x][y])
		return dp[x][y];
	vis[x][y] = 1;
	double ret = 6, div = 6;
	for(int i = 1; i <= 6; i++)
	{
		pair<int, int> p = next(x, y, i);
		if(p.first == x && p.second == y)
			div--;
		else
		{
			//printf("%d %d %d\n", p.first, p.second, p.first-mat[x][y]);
			//if(mat[p.first][p.second] != 0 && p.first+mat[p.first][p.second] < 10)
				ret += min(solve(p.first, p.second), solve(p.first-mat[p.first][p.second], p.second));
			//else
				//ret += solve(p.first, p.second);
		}
	}
	//flag = 1;
	//printf("%lf\n", div);
	return dp[x][y] = ret/div;
}

int main()
{
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			scanf("%d", &mat[i][j]);
	printf("%.7lf\n", solve(9, 0));
	return 0;
}
