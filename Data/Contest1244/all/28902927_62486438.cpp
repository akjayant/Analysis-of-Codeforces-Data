#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=300050;
const ll llINF=~(1ll<<63);

int head[MAXN],_next[MAXN],to[MAXN],cnt;
ll cost[MAXN][5];

void add_Edge(int u,int v)
{
    _next[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}

bool vis[MAXN],flag;
int num[MAXN];

void dfs(int cur,int now)
{
    num[cur]=now;
    for(int i=head[cur];i;i=_next[i])
    {
        int v=to[i];
        if(num[v]==num[now])flag=1;
        if(!(~num[v]))
        {
            dfs(v,(now+1)%3);
        }
    }
}

int num2[MAXN],flag1;

void dfs2(int cur,int now)
{
    num2[cur]=now;
    for(int i=head[cur];i;i=_next[i])
    {
        int v=to[i];
        if(num2[v]==num2[now])flag1=1;
        if(!(~num2[v]))
        {
            dfs2(v,(now+2)%3);
        }
    }
}

int du[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int j=1;j<=3;j++)
        for(int i=1;i<=n;i++)
        scanf("%lld",&cost[i][j]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_Edge(u,v);
        add_Edge(v,u);
        du[u]++;
        du[v]++;
    }
    memset(num,-1,sizeof(num));
    memset(num2,-1,sizeof(num2));
    int s=0;
    for(int i=1;i<=n;i++)if(du[i]>2)return puts("-1"),0;
    for(int i=1;i<=n;i++)
        if(du[i]==1)
        s=i;
    dfs(s,1);
    dfs2(s,1);
    ll ans=llINF,ansnode=0;
    //if(flag&&flag1)return puts("-1"),0;
    for(int col=0;col<3;col++)
    {
        ll tmp=0;
        for(int j=1;j<=n;j++)
        {
            tmp+=cost[j][(num[j]+col)%3+1];
        }
        if(tmp<ans)
        {
            ans=tmp;
            ansnode=col;
        }
    }
    for(int col=3;col<=5;col++)
    {
        ll tmp=0;
        for(int j=1;j<=n;j++)
        {
            tmp+=cost[j][(num2[j]+col)%3+1];
        }
        if(tmp<ans)
        {
            ans=tmp;
            ansnode=col;
        }
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++)
        if(ansnode<3)
        printf("%lld ",(num[i]+ansnode)%3+1);
    else printf("%lld ",(num2[i]+ansnode)%3+1);
    return 0;
}
