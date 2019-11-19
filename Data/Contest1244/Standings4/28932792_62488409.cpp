#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int ms = 1e5 + 10;
ll c[ms][3];
vector<int> g[ms];
int co[ms], tmp[ms];
int cc[3];
ll dfs(int cur, int f, int color)
{
    tmp[cur] = cc[color];
    ll res = 0;
    for (int i : g[cur])
    {
        if (i == f) continue;
        res = dfs(i, cur, (color + 1) % 3);
    }
    return c[cur][cc[color]] + res;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i][0];
    for (int i = 1; i <= n; ++i) cin >> c[i][1];
    for (int i = 1; i <= n; ++i) cin >> c[i][2];
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (g[i].size() > 2)
        {
            cout << -1;
            return 0;
        }
        if (g[i].size() == 1) s = i;
    }
    cc[0] = 0, cc[1] = 1, cc[2] = 2;
    ll res = dfs(s, 0, 0);
    for (int i = 1; i <= n; ++i) co[i] = tmp[i];
    cc[0] = 0, cc[1] = 2, cc[2] = 1;
    ll t = dfs(s, 0, 0);
    if (t < res)
    {
        for (int i = 1; i <= n; ++i) co[i] = tmp[i];
        res = t;
    }
    cc[0] = 1, cc[1] = 2, cc[2] = 0;
    t = dfs(s, 0, 0);
    if (t < res)
    {
        for (int i = 1; i <= n; ++i) co[i] = tmp[i];
        res = t;
    }
    cc[0] = 1, cc[1] = 0, cc[2] = 2;
    t = dfs(s, 0, 0);
    if (t < res)
    {
        for (int i = 1; i <= n; ++i) co[i] = tmp[i];
        res = t;
    }
    cc[0] = 2, cc[1] = 1, cc[2] = 0;
    t = dfs(s, 0, 0);
    if (t < res)
    {
        for (int i = 1; i <= n; ++i) co[i] = tmp[i];
        res = t;
    }
    cc[0] = 2, cc[1] = 0, cc[2] = 1;
    t = dfs(s, 0, 0);
    if (t < res)
    {
        for (int i = 1; i <= n; ++i) co[i] = tmp[i];
        res = t;
    }
    cout << res << "\n";
    for (int i = 1; i <= n; ++i)
    {
        cout << co[i] + 1 << " ";
    }
    return 0;
}
