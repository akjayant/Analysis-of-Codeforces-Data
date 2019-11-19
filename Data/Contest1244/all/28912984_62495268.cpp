#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 100005;
vector<int>adj[mx];
ll c[4][mx],sm,cl[mx];
void dfs(int u, int p, int cu, int cp)
{
    for(auto v : adj[u])
    {
        if(v==p)continue;
        if(cu!=1 && cp!=1)cl[v]=1,sm+=c[1][v];
        else if(cu!=2 && cp!=2)cl[v]=2,sm+=c[2][v];
        else if(cu!=3 && cp!=3)cl[v]=3,sm+=c[3][v];

        dfs(v,u,cl[v],cl[u]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++)cin >> c[1][i];
    for(int i=1;i<=n;i++)cin >> c[2][i];
    for(int i=1;i<=n;i++)cin >> c[3][i];

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int fg = 0;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()>2)
        {
            fg = 1;
            break;
        }
    }
    if(fg)cout << -1 << endl, exit(0);
    int root, child;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()==1)
        {
            root = i;
            child = adj[i][0];
            break;
        }
    }
    ll ans = 1e18;
    pair<int,int>pr;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(i==j)continue;
            sm = 0;
            sm+=c[j][root]+c[i][child];
            cl[child] = i, cl[root] = j;
            dfs(child, root, i, j);
            if(sm<ans)
            {
                ans = sm;
                pr = {i,j};
            }
        }
    }
    int i = pr.first, j = pr.second;
    sm = 0;
    sm+=c[j][root]+c[i][child];
    cl[child] = i, cl[root] = j;
    dfs(child, root, i, j);
    cout << sm << "\n";
    for(i=1;i<=n;i++)
    {
        cout << cl[i] << " ";
    }
    cout << "\n";
    return 0;
}
