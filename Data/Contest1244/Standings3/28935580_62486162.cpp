#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;

ll c[3][maxn];
vector<int> G[maxn];

int tag[maxn], mp[maxn], tot;

ll dp[maxn][3][3];

void dfs(int u, int pre)
{
    tag[u] = tot;
    mp[tot] = u;
    tot ++;
    for(auto v : G[u]) if(v != pre) dfs(v, u);
}

int gg[6][3] = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
int col[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 3; i ++)
        for(int j = 1; j <= n; j ++)
            scanf("%lld", &c[i][j]);
    for(int i = 1; i < n; i ++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; i ++) if(G[i].size() > 2) return 0 * puts("-1");
    int s = 0;
    for(int i = 1; i <= n; i ++) if(G[i].size() == 1) { s = i; break; }
    dfs(s, 0);
    ll res = 0x3f3f3f3f3f3f3f3f;
    int ansp = -1;
    for(int p = 0; p < 6; p ++)
    {
        ll tmp = 0;
        for(int i = 0; i < n; i ++)
        {
            tmp += c[gg[p][i % 3] - 1][mp[i]];
        }
        if(tmp < res)
        {
            ansp = p;
            res = tmp;
        }
    }
    printf("%lld\n", res);
    for(int i = 0; i < n; i ++)
    {
        col[mp[i]] = gg[ansp][i % 3];
    }
    for(int i = 1; i <= n; i ++) printf("%d ", col[i]);
    return 0;
}
