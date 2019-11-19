#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <random>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
#define LL long long

using namespace std;

const int mod = 1e9+7;
const int maxn = 11234567;

LL cost[112345][3];
int in[112345];
int nt[112345][2];
LL dp[112345][3][3];
LL pre[112345][3][3][3]; // 0: pre_point 1: pre_pre_color 2: pre_color;
bool vis[112345];
int col[112345];

void dfs_print(int st, int en, int cc1, int cc2)
{
    int cc0 = 3-cc1-cc2;
    if (en != st) dfs_print(st, pre[en][cc1][cc2][0], cc0, cc1);
    col[en] = cc2+1;
}

int main()
{
    ios::sync_with_stdio(false);

    int t,n;

    scanf("%d", &n);

    for (int i = 0; i < 3; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%lld", &cost[j][i]);

    int u, v, g;
    memset(in, 0, sizeof(in));
    for (int i = 0; i < n-1; ++i)
    {
        scanf("%d%d", &u, &v);
        nt[u][in[u]] = v;
        nt[v][in[v]] = u;
        in[u]++;
        in[v]++;
        if (in[u] == 3 || in[v] == 3)
        {
            puts("-1");
            return 0;
        }
    }

    memset(dp, -1, sizeof(dp));

    int st;
    for (int i = 1; i <= n; ++i)
    {
        if (in[i] == 1)
        {
            st = i;
            break;
        }
    }

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            dp[st][i][j] = cost[st][j];

    u = st;
    memset(vis, 0, sizeof(vis));
    vis[u] = 1;
    while (u == st || in[u] != 1)
    {
        for (int i = 0; i < in[u]; ++i)
        {
            v = nt[u][i];
            if (vis[v]) continue;
            vis[v] = 1;
            g = v;
            for (int c1 = 0; c1 < 3; ++c1)
            {
                for (int c2 = 0; c2 < 3; ++c2)
                {
                    if (c2 == c1 || dp[u][c1][c2] == -1) continue;
                    int c3 = 3 - c1 - c2;
                    if (dp[v][c2][c3] == -1 || dp[v][c2][c3] < dp[u][c1][c2] + cost[v][c3])
                    {
                        dp[v][c2][c3] = dp[u][c1][c2] + cost[v][c3];
                        pre[v][c2][c3][0] = u;
                        pre[v][c2][c3][1] = c1;
                        pre[v][c2][c3][2] = c2;
                    }
                }
            }
        }
        u = g;
    }
    int en = u;

    LL cst = -1;
    int cc1, cc2;
    for (int c1 = 0; c1 < 3; ++c1)
        for (int c2 = 0; c2 < 3; ++c2)
        {
            if (c1 == c2 || dp[en][c1][c2] == -1) continue;
            if (cst == -1 || cst > dp[en][c1][c2])
            {
                cst = dp[en][c1][c2];
                cc1 = c1;
                cc2 = c2;
            }
        }

    printf ("%lld\n", cst);

    u = en;

    dfs_print(st, en, cc1, cc2);

    for (int i = 1; i <= n; ++i)
    {
        if (i != 1) putchar(' ');
        printf("%d", col[i]);
    }
    puts("");

    return 0;
}
