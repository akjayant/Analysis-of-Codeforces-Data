#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

int64_t prc[111111][3];

vector<int> nextv[111111];
int order[1111111];
int on = 0;
int pp[111111];

void dfs1(int n, int p = -1)
{
    order[on++] = n;
    pp[n] = p;
    for (auto x : nextv[n])
    {
        if (x == p)
        {
            continue;
        }
        dfs1(x, n);
    }
}

int ans[111111];

int main()
{
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &prc[i][0]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &prc[i][1]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &prc[i][2]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%i %i", &x, &y);
        x--;
        y--;
        nextv[x].push_back(y);
        nextv[y].push_back(x);
    }
    int ss = 0;
    for (int i = 0; i < n; i++)
    {
        if (nextv[i].size() > 2)
        {
            printf("-1");
            return 0;
        }
        if (nextv[i].size() == 1)
            ss = i;
    }
    dfs1(ss);
    int pats[6][3] = {
        0, 1, 2,
        0, 2, 1,
        1, 0, 2,
        1, 2, 0,
        2, 1, 0,
        2, 0, 1,
    };
    int64_t best = INT64_MAX;
    int bp = 0;
    for (int j = 0; j < 6; j++)
    {
        int64_t s = 0;
        for (int i = 0; i < n; i++)
        {
            int v = order[i];
            s += prc[v][pats[j][i%3]];
        }
        if (s < best)
        {
            best = s;
            bp = j;
        }
    }
    printf("%lld\n", best);
    for (int i = 0; i < n; i++)
    {
        ans[order[i]] = pats[bp][i%3];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%i ", ans[i]+1);
    }
}
