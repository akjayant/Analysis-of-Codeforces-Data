#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define pb push_back
#define ll long long
#define pi pair<int,int>
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int n,deg[100100],to[100100],col[100100],root=-1;
vector <int> adj[100100];
ll c[100100][5],dp[100100][5][5];
ll Solve(int i,int p1,int p2)
{
    if(i==-1)
        return 0;
    if(dp[i][p1][p2]+1)
        return dp[i][p1][p2];
    ll &ret=dp[i][p1][p2];
    ret=1e17;
    for(int j=1;j<=3;j++)
        if(j!=p1&&j!=p2)
            ret=min(ret,c[i][j]+Solve(to[i],j,p1));
    return ret;
}
void dfs(int u,int p)
{
    for(int v : adj[u])
    {
        if(v==p) continue;
        dfs(v,u);
        to[u]=v;
    }
    return;
}
void path(int i,int p1,int p2)
{
    if(i==-1)
        return;
    ll ret=dp[i][p1][p2];
    for(int j=1;j<=3;j++)
        if(j!=p1&&j!=p2)
        {
            if(ret==c[i][j]+Solve(to[i],j,p1))
            {
                col[i]=j;
                path(to[i],j,p1);
                return;
            }
        }
    return;
}
int main()
{
    go;
    memset(to,-1,sizeof to);
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=n;j++)
        cin>>c[j][i];
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        deg[x]++;
        deg[y]++;
        adj[x].pb(y);
        adj[y].pb(x);
        if(deg[x]>=3||deg[y]>=3)
            return cout<<-1,0;
    }
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==1)
        {
            root=i;
            break;
        }
    }
    if(root==-1)
        return cout<<-1,0;
    dfs(root,-1);
    ll ans=Solve(root,0,0);
    cout<<ans<<endl;
    path(root,0,0);
    for(int i=1;i<=n;i++)
        cout<<col[i]<<" ";
    return 0;
}
