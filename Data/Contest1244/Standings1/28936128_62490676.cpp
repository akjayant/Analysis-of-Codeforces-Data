#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+10;
ll c[3][maxn];
int n;
vector<int> G[maxn];
int degree[maxn];
int vis[maxn],av[maxn];

ll dfs(int pre,int i,int now,int j)
{
    int k;
    for(k=0;k<3;k++)
        if(k!=i&&k!=j)
            break;
    vis[now]=j;
    for(int p=0;p<G[now].size();p++)
    {
        int u=G[now][p];
        if(vis[u]==-1)
            return c[j][now]+dfs(now,j,u,k);
    }
    return c[j][now];
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<3;i++)
        for(int j=1;j<=n;j++)
            scanf("%I64d",&c[i][j]);
    int u,v;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&u,&v);
        degree[u]++;
        degree[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int s=0,t=0;
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(degree[i]>2)
        {
            flag=false;
            break;
        }
        else if(degree[i]==1)
        {
            if(s==0)
                s=i;
            else
                t=i;
        }
    }
    if(flag)
    {
        ll ans=0x3f3f3f3f3f3f3f3f;
        
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                if(i==j)
                    continue;
                ll tmp=0;
                memset(vis,-1,sizeof(vis));
                vis[s]=i;
                tmp+=c[i][s];
                tmp+=dfs(s,i,G[s][0],j);
                if(tmp<ans)
                {
                    for(int i=1;i<=n;i++)
                        av[i]=vis[i];
                    ans=tmp;
                }
            }
        printf("%I64d\n",ans);
        for(int i=1;i<=n;i++)
        {
            printf("%d",av[i]+1);
            if(i==n)
                printf("\n");
            else
                printf(" ");
            
        }
    }
    else
    {
        printf("-1\n");
    }
    
    
}