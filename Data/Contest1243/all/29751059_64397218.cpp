#include <bits/stdc++.h>

#define renew(x) memset(x, 0, sizeof x)
#define in(x) scanf("%d", &x)

using namespace std;

const int maxn = 1e6 + 10;
int e1[maxn], e2[maxn], idx1[maxn], idx2[maxn];
bool mark[maxn];
vector<int> adj[maxn], g[maxn], comp[maxn], s1, s2;
vector<vector<bool>> mat_s1, mat_s2;

void dfs(int u, int ind)
{
    mark[u] = true, comp[ind].push_back(u);
    for (int v : g[u])
        if (!mark[v])
            dfs(v, ind);
}

int main()
{
    int n, m;
    in(n), in(m);

    for (int i = 0; i < m; i++)
    {
        in(e1[i]), in(e2[i]);
        adj[e1[i]].push_back(e2[i]);
        adj[e2[i]].push_back(e1[i]);
    }

    int delta = 1;
    for (int i = 2; i <= n; i++)
        if (adj[i].size() < adj[delta].size())
            delta = i;

    int delta_n = adj[delta].size();
    mat_s1.assign(delta_n + 10, vector<bool>(delta_n + 10));
    mat_s2.assign(delta_n + 10, vector<bool>(n - delta_n + 10));

    for (int v : adj[delta])
        mark[v] = true;

    for (int i = 1; i <= n; i++)
        if (mark[i])
            s1.push_back(i);
        else
            s2.push_back(i);

    for (int i = 0; i < s1.size(); i++)
        idx1[s1[i]] = i;

    for (int i = 0; i < s2.size(); i++)
        idx2[s2[i]] = i;

    for (int i = 0; i < m; i++)
    {
        int u = e1[i], v = e2[i];

        if (mark[u] && mark[v])
        {
            u = idx1[u], v = idx1[v];
            mat_s1[u][v] = mat_s1[v][u] = true;
        }
        else if (mark[u] || mark[v])
        {
            if (mark[u])
                u = idx1[u], v = idx2[v];
            else
                u = idx2[u], v = idx1[v], swap(u, v);
            mat_s2[u][v] = true;
        }
    }

    for (int u : s1)
        for (int v : s2)
            if (!mat_s2[idx1[u]][idx2[v]])
                g[u].push_back(v), g[v].push_back(u);

    for (int u : s1)
        for (int v : s1)
            if (u > v && !mat_s1[idx1[u]][idx1[v]])
                g[u].push_back(v), g[v].push_back(u);

    renew(mark);
    int ind = 1;
    for (int u : s2)
        if (!mark[u])
            dfs(u, ind);

    for (int u : s1)
        if (!mark[u])
            dfs(u, ++ind);

    printf("%d\n", ind - 1);

    return 0;
}