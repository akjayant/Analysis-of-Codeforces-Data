#include<bits/stdc++.h>
using namespace std;
#define M 12
typedef pair<int, int> pii;

int ara[M][M];
double dp[M][M][2];

pii getNxt(int i, int j)
{
    if(!i || !j) return {0, 0};
    if(i == 1 && j == 1) return {0, 0};

    if(i%2 == 0 && j == 10) return {i-1, j};
    if(i%2 && j == 1) return {i-1, j};
    if(i%2 == 0) return {i, j+1};
    return {i, j-1};
}

double cnt(int x, int y, int flag)
{
    if(x == 1 && y == 1) return 0;

    double &res = dp[x][y][flag];
    if(res > -.5) return res;

    int nx = x, ny = y;
    int cutu = 6;

    double sum = 6;

    for(int i = 0; i < 6; i++)
    {
        pii p = getNxt(nx, ny);

        if(!p.first) cutu--;
        else sum += cnt(p.first, p.second, 0);

        nx = p.first, ny = p.second;
    }

    res = sum/cutu;

    if(!flag && ara[x][y]) res = min(res, cnt(x-ara[x][y], y, 1));

    return res;
}

int main()
{
    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++) scanf("%d", &ara[i][j]);
    }

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < M; j++) dp[i][j][0] = dp[i][j][1] = -1;
    }

    printf("%.10lf\n", cnt(10, 1, 1));

    return 0;
}
