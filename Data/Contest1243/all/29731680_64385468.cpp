#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, vis[maxn], cnt[maxn], res;
set<int> s, G[maxn];
queue<int> q;
void bfs(int u)
{
    vis[u] = 1;
    s.erase(u);
    q.push(u);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        set<int>::iterator it;
        for (it = s.begin(); it != s.end();)
        {
            int v = *it;
            ++it;
            if (G[u].find(v) == G[u].end())
            {
                s.erase(v);
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int m, u, v, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        s.insert(i);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].insert(v);
        G[v].insert(u);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            ans++;
            bfs(i);
        }
    printf("%d\n", ans - 1);
}