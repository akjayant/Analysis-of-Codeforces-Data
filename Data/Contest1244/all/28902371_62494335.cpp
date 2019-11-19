#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int n;
ll a[100100][3];
vector < vector < int > > V;
int deg[100100];
bool vis[100100];
vector < vector < int > > edge;
int par[100100];
int colors[100100];
stack < int > stk;
void dfs(int u)
{
    vis[u] = 1;
    stk.push(u);
    for (auto v : V[u])
        if (!vis[v])
        {
            edge[u].push_back(v);
            vis[v] = 1;
            par[v] = u;
            dfs(v);
        }
}
ll dp[100100][3][3];

int main(){
    for (int i = 0 ; i < 100100 ; ++i)
        for (int j = 0 ; j < 3; ++j)
            for (int k = 0 ; k < 3 ; ++k)
                dp[i][j][k] = 1e15;

    scanf("%d", &n);
    V.resize(n+10);
    edge.resize(n+10);
    for (int j = 0; j < 3; ++j)
        for (int i = 0; i <n; ++i)
            scanf("%lld", &a[i+1][j]);
	for (int i = 1, x, y; i < n; ++i)
	{
	    scanf("%d%d", &x, &y);
	    V[x].push_back(y);
	    V[y].push_back(x);
	    ++deg[x];
	    ++deg[y];
	}
	int idx =0 ;
    for (int i = 1; i <= n ; ++i)
    {
        if (deg[i] > deg[idx])
            idx = i;
        if (deg[i] == 1)
        {
            for (int j = 0 ; j < 3; ++j)
                for (int k = 0 ; k < 3; ++k)
                    dp[i][j][k] = a[i][j];
        }
    }
    sort(deg, deg + 100100) ;
    if (deg[100100-1] > 2 || deg[100100-2] > 2)
        return puts("-1");
    dfs(idx);
    int u,p;
    while (stk.size())
    {
        u = stk.top();
        stk.pop();
        p = par[u];
        if (u == idx || p == idx) continue;
        for (int j = 0; j < 3; ++j)
            for (int k = 0 ; k < 3; ++k)
                if (j != k)
                    dp[p][j][k] = a[p][j] + min(dp[u][k][(j+1)%3], dp[u][k][(j+2)%3]);
    }
    if (deg[100100-1] == 1)
    {
        ll ans = LLONG_MAX;
        for (int i = 0 ; i< 3; ++i)
            for (int j = 0 ; j < 3; ++j)
                ans = min(ans, dp[idx][i][j]);
        printf("%lld\n", ans);
    }
    else
    {
        ll ans = LLONG_MAX;
        int colorroot, colorleftChild, colorRightchild;
        int arr[6] = {0, 1, 2, 3, 4, 5};
        for (int i = 0 ; i < 3; ++i)
        for (int j = 0 ; j < 3; ++j)
        for (int k = 0 ; k < 3; ++k)
        {
            if (j == k) continue;
            if (i == j) continue;
            if (i == k) continue;
            if (a[idx][i] + dp[edge[idx][0]][j][k] + dp[edge[idx][1]][k][j] < ans)
                ans = a[idx][i] + dp[edge[idx][0]][j][k] + dp[edge[idx][1]][k][j],
                colorroot = i,
                colorleftChild = j, colorRightchild = k;
        }
        printf("%lld\n", ans);
        colors[idx] = colorroot;
        colors[edge[idx][0]] = colorleftChild;
        colors[edge[idx][1]] = colorRightchild;
        int u = edge[idx][0];
        int tmp = colorroot;
        while (edge[u].size())
        {
            u = edge[u][0];
            int ba = 0;
            bool bla[3] = {};
            bla[colorroot] = 1;
            bla[colorleftChild] = 1;
            for (int i = 0; i < 3; ++i)
                if (bla[i]);
                else ba = i;
            colors[u] = ba;
            colorroot = colorleftChild;
            colorleftChild = ba;
        }
        colorroot = tmp;
        u = edge[idx][1];
        while (edge[u].size())
        {
            u = edge[u][0];
            int ba = 0;
            bool bla[3] = {};
            bla[colorroot] = 1;
            bla[colorRightchild] = 1;
            for (int i = 0; i < 3; ++i)
                if (bla[i]);
                else ba = i;
            colors[u] = ba;
            colorroot = colorRightchild;
            colorRightchild = ba;
        }
        for (int i = 1; i <= n; ++i)
            printf("%d ", colors[i]+1);
    }

	return 0;
}
