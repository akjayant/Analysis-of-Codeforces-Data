#include<bits/stdc++.h>
#define ll long long
#define S second
#define F first

using namespace std;

const int N = 1e5+5;

vector<int> adj[N];

int arr[N], col[N], nxt[N], sz, n;
ll dp[4][4][N];
ll cs[4][N];

ll solve(int prv, int prv2, int ind)
{
    if(ind == n) return 0;
    ll &ret = dp[prv][prv2][ind];
    if(~ret) return ret;
    ret = 1e16;
    for(int i = 0 ; i < 3 ; i++)
    {
        if(i != prv and i != prv2)
        {
            ret = min(ret, solve(i, prv, ind+1) + cs[i][arr[ind]]);
        }
    }
    return ret;
}

void build(int prv, int prv2, int ind)
{
    if(ind == n) return;
    ll ret = dp[prv][prv2][ind];
    for(int i = 0 ; i < 3 ; i++)
    {
        if(i != prv and i != prv2 and ret == solve(i, prv, ind+1) + cs[i][arr[ind]])
        {
            col[arr[ind]] = i+1;
            build(i, prv, ind+1);
            return;
        }
    }
}

void dfs(int node, int p)
{
    arr[sz++] = node;
    for(auto i:adj[node])
    {
        if(i == p) continue;
        dfs(i, node);
    }
}

int main()
{
    memset(dp, -1, sizeof dp);
    int u, v;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) scanf("%lld", cs[0] + i);
    for(int i = 0 ; i < n ; i++) scanf("%lld", cs[1] + i);
    for(int i = 0 ; i < n ; i++) scanf("%lld", cs[2] + i);
    for(int i = 0 ; i < n - 1 ; i++)
    {
        scanf("%d%d", &u, &v);
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(adj[i].size() > 2) return puts("-1"), 0;
        if(adj[i].size() == 1) s = i;
    }
    dfs(s, -1);
    // printf("%d\n", sz);
    // for(int i = 0 ; i < sz ; i++) printf("%d ", arr[i]);
    printf("%lld\n", solve(3, 3, 0));
    build(3, 3, 0);
    for(int i = 0 ; i < n ; i++) printf("%d ", col[i]);
}
