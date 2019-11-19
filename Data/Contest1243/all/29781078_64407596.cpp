#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <list>

using namespace std;
const int N = 2e5+10;
bool vis[N];
vector <int> a[N], ans;
list <int> g;//用vector超时
list <int>:: iterator it, tmp;
int n, m;

int main()
{
    scanf("%d %d", &n, &m);
    int x, y;
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i) g.push_back(i);
    while(!g.empty())
    {
        ans.push_back(1);
        queue <int> q;
        it = g.begin();
        q.push((*it));
        g.erase(it);
        while(!q.empty())
        {
            memset(vis, 0, sizeof(vis));
            int u = q.front();
            q.pop();
            for(int i = 0; i < a[u].size(); ++i)
                vis[a[u][i]] = 1;
            for(it = g.begin(); it != g.end();)
                if(!vis[(*it)])
                {
                    ++ans.back();
                    q.push((*it));
                    tmp = it;
                    ++it;
                    g.erase(tmp);
                }
                else ++it;//
        }
    }
    printf("%d\n", ans.size()-1);
    return 0;
}
