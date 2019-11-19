#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
int n,m;
vector<int> e[N];
int dfn[N],scc_idx[N],low[N],tim,idx,sz[N],deg[N];
bool vis[N];stack<int> stk;
void tarjan(int pos)
{
    dfn[pos] = low[pos] = ++tim;vis[pos] = 1;stk.push(pos);
    for (auto &i : e[pos])
        if (!dfn[i]) tarjan(i),low[pos] = min(low[pos],low[i]);
        else if (vis[i]) low[pos] = min(low[pos],dfn[i]);
    if (dfn[pos] == low[pos])
    {
        ++idx;
        while (!stk.empty())
        {
            int nd = stk.top();stk.pop();
            vis[nd] = 0;scc_idx[nd] = idx;++sz[idx];
            if (nd == pos) break;
        }
    }
}
int main ()
{
    ios::sync_with_stdio(false);
    int T;cin >> T;
    while (T--)
    {
        cin >> n >> m;
        tim = idx = 0;
        int t1,t2;
        for (int i = 1;i <= n;i++) e[i].clear();
        for (int i = 1;i <= m;i++)
        {
            cin >> t1 >> t2;
            if (t1 != t2) e[t1].push_back(t2);
        }
        for (int i = 1;i <= n;i++)
            scc_idx[i] = sz[i] = dfn[i] = low[i] = deg[i] = vis[i] = 0;
        for (int i = 1;i <= n;i++)
            if (!dfn[i]) tarjan(i);
        for (int i = 1;i <= n;i++)
            for (auto &j : e[i])
                if (scc_idx[i] != scc_idx[j]) ++deg[scc_idx[i]];
        if (sz[scc_idx[1]] == n) { puts("NO");continue; }
        bool fl = 0;
        for (int i = 1;i <= idx;i++)
            if (!deg[i] && sz[i])
            {
                puts("YES");fl = 1;
                vector<int> ans[2];
                for (int j = 1;j <= n;j++)
                    ans[scc_idx[j] == i].push_back(j);
                printf("%d %d\n",ans[1].size(),ans[0].size());
                for (auto &i : ans[1]) printf("%d ",i);
                puts("");
                for (auto &i : ans[0]) printf("%d ",i);
                puts("");
                break;
            }
        if (!fl) puts("NO");
    }
    return 0;
}