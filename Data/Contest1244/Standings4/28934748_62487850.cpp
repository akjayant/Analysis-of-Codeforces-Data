#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int NMAX = 1e5 + 5;
const ll INF = 1e16;

int n;
int cost[4][NMAX];
vector <int> G[NMAX];
int deg[NMAX];
int p[NMAX], fiu[NMAX];
ll dp[4][4][NMAX];
int urm[4][4][NMAX];
int rad, capat;
int cul[NMAX];

bool lant()
{
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 1)
            cnt1++;
        else if (deg[i] == 2)
            cnt2++;

    return cnt1 + cnt2 == n && cnt1 == 2;
}

void dfs(int nod)
{
    for (auto v: G[nod])
        if (v != p[nod])
        {
            p[v] = nod;
            fiu[nod] = v;
            dfs(v);
        }
}

void getDinamica(int nod)
{
    if (deg[nod] == 1 && nod != rad)
    {
        capat = nod;

        for (int i = 1; i <= 3; i++)
            dp[i][0][nod] = cost[i][nod];
        return;
    }

    getDinamica(fiu[nod]);

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            for (int k = 0; k <= 3; k++)
            {
                if (i != j && j != k && i != k)
                    if (dp[j][k][fiu[nod]] + cost[i][nod] < dp[i][j][nod])
                    {
                        dp[i][j][nod] = dp[j][k][fiu[nod]] + cost[i][nod];
                        urm[i][j][nod] = k;
                    }
            }
        }
    }
}

void refa(int nod, int i, int j)
{
    cul[nod] = i;

    if (nod == capat)
        return;

    refa(fiu[nod], j, urm[i][j][nod]);
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);

        deg[u]++;
        deg[v]++;
    }

    if (!lant())
    {
        printf("-1");
        return 0;
    }

    rad = 0;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 1)
            rad = i;

    dfs(rad);

    for (int i = 0; i <= 3; i++)
        for (int j = 0; j <= 3; j++)
            for (int nod = 1; nod <= n; nod++)
                dp[i][j][nod] = INF;
    
    //cout << p[1];
    //return 0;
    getDinamica(rad);

    ll rez = INF;

    //cout << dp[2][1][2];
    //return 0;

    int ki = 0, kj = 0;

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            if (dp[i][j][rad] < rez)
            {
                rez = dp[i][j][rad];
                ki = i;
                kj = j;
            }

    printf("%I64d\n", rez);

    refa(rad, ki, kj);

    for (int i = 1; i <= n; i++)
        printf("%d ", cul[i]);

    return 0;
}