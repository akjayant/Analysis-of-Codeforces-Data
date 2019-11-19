/*jai mata di
let's rock*/
#include<bits/stdc++.h>
using namespace std;
const long long int Inf=1e18;
const int N=100004;
long long int cost[4][N];
int s[N][4][4];
int deg[N];
int color[N];
vector<int>g[N];
long long dfs(int u,int p,int cp,int cpp)
{
    long long res=Inf;
    int col;
    for(int c=1;c<=3;c++)
    {
        if(c==cp || c==cpp) continue;
        for(int i=0;i<g[u].size();i++)
        {
           int v=g[u][i];
           if(v==p) continue;
           long long res1=cost[c][u]+dfs(v,u,c,cp);
           if(res1<res)
              {
                  col=c;
                  res=res1;
              }
        }
    }
    if(res==Inf)
    {
        for(int c=1;c<=3;c++)
        {
            if(c==cp || c==cpp) continue;
            long long res1=cost[c][u];
            if(res1<res)
            {
                col=c;
                res=res1;
            }
        }
    }
    s[u][cp][cpp]=col;
    return res;
}
void solve(int u,int p,int cp,int cpp)
{
    color[u]=s[u][cp][cpp];
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==p) continue;
        solve(v,u,color[u],cp);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
        scanf("%I64d",&cost[1][i]);
    for(i=1;i<=n;i++)
        scanf("%I64d",&cost[2][i]);
    for(i=1;i<=n;i++)
        scanf("%I64d",&cost[3][i]);
    for(i=1;i<n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        deg[u]++;
        deg[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int root;
    int cnt=0;
    for(i=1;i<=n;i++)
    {
        if(deg[i]>2) cnt++;
        if(deg[i]==1)
            root=i;
    }
    if(cnt>0)
        printf("-1\n");
    else
    {
       long long ans=dfs(root,0,0,0);
       solve(root,0,0,0);
       printf("%I64d\n",ans);
       for(i=1;i<=n;i++) printf("%d ",color[i]);
       printf("\n");
    }
    return 0;
}
