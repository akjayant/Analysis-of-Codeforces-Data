#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int head[200010],last[200010],to[200010],cnt=0,fa[200010],deg[200010];
bool vis[200010],vis2[200010];
void add(int u,int v)
{
    cnt++;
    last[cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
    deg[v]++;
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    while(m--)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    int u=0,mi=n;
    for(int i=1;i<=n;i++)
        if(deg[i]<mi)
        {
            mi=deg[i];
            u=i;
        }
    for(int i=head[u];i;i=last[i])
        vis[to[i]]=true;
    for(int i=1;i<=n;i++)
        if(!vis[i])
            fa[i]=u;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            continue;
        memset(vis2,0,sizeof(vis2));
        int x=find(i);
        for(int j=head[i];j;j=last[j])
            vis2[to[j]]=true;
        for(int j=1;j<=n;j++)
        {
            if(vis2[j])
                continue;
            int y=find(j);
            fa[y]=x;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(fa[i]==i)
            ans++;
    printf("%d\n",ans-1);
    return 0;
}