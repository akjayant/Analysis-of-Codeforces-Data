#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, dp[100005][4][4], cost[100005][4], wrong = 0, leaf, sol[100005];
vector <ll> Muchii[100005];

void DFS(ll nod, ll tata)
{
    ll contor = 0;
    for (auto it : Muchii[nod])
    {
        if (it == tata)
            continue;
        ++contor;
        DFS(it, nod);
        for (int j = 1; j <= 3; ++j)
        {
            for (int i = 1; i <= 3; ++i)
            {
                for (int k = 1; k <= 3; ++k)
                {
                    if (i == j || i == k || k == j)
                        continue;
                    dp[nod][j][i] = min(dp[nod][j][i], 1LL * cost[nod][j] + dp[it][k][j]);
                }
            }
        }
    }
    if (contor == 0)
    {
        for (int j = 1; j <= 3; ++j)
        {
            for (int i = 1; i <= 3; ++i)
            {
                if (i != j)
                    dp[nod][i][j] = cost[nod][i];
            }
        }
    }
}

void reconst(int nod, int cul1, int cul2, int tata)
{
    sol[nod] = cul1;
    for (auto it : Muchii[nod])
    {
        if (it == tata)
            continue;
        for (int j = 1; j <= 3; ++j)
        {
            if (j == cul1 || j == cul2)
                continue;
            reconst(it, j, cul1, nod);
        }
    }
}

int main()
{
    cin >> n;
    for (int j = 1; j <= 3; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            cin >> cost[i][j];
        }
    }
    for (int i = 1; i < n; ++i)
    {
        ll x, y;
        cin >> x >> y;
        Muchii[x].push_back(y);
        Muchii[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            for (int k = 1; k <= 3; ++k)
            {
                dp[i][j][k] = 1LL * 10000000000000000;
            }
        }
        if (Muchii[i].size() > 2)
        {
            cout << -1;
            return 0;
        }
        if (Muchii[i].size() == 1)
        {
            leaf = i;
        }
    }
    DFS(leaf, -1);
    ll minim = 1LL * 10000000000000000;
    int cul1, cul2;
    for (int j = 1; j <= 3; ++j)
    {
        for (int k = 1; k <= 3; ++k)
        {
            if (dp[leaf][j][k] < minim)
            {
                minim = dp[leaf][j][k];
                cul1 = j;
                cul2 = k;
            }
        }
    }
    cout << minim << "\n";
    reconst(leaf, cul1, cul2, -1);
    for (int i = 1; i <= n; ++i)
    {
        cout << sol[i] << " ";
    }
    return 0;
}
