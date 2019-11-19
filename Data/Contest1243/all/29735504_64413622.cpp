#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)

int n,m,res,deg[N], d[N];
vector < int > g[N];

int root(int u){
    return u == d[u] ? u : d[u] = root(d[u]);
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n>>m;
	for (int i = 1; i <= n; ++i){
        deg[i] = n - 1;
        d[i] = i;
	}
	for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        deg[u]--; deg[v]--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        sort(g[i].begin(), g[i].end());

    int ret = 50;
    int cnt = 0;
    for (int i = 1; i <= n && ret--; ++i)
        if (deg[i] >= n / 50)
        for (int j = 1, j1 = 0; j <= n; j ++){
                while (j1 < g[i].size() && g[i][j1] < j) j1++;
                if (!g[i].empty() && g[i][j1] == j) continue;
                int u = root(i), v = root(j);
                if (u == v) continue;
                cnt++;
                d[u] = v;
            }

    for (int i = 1; i <= n; ++i)
        if (deg[i] <= 400) {
            for (int j = 1, j1 = 0; j <= n; j ++){

                while (j1 < g[i].size() && g[i][j1] < j) j1++;
                if (!g[i].empty() && g[i][j1] == j) continue;
                int u = root(i), v = root(j);
                if (u == v) continue;
                cnt++;
                d[u] = v;
            }
        }
    cout << n - cnt - 1;
	return 0;
}

