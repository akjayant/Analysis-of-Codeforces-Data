#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e3+50;
const ll llINF=~(1ll<<63);
const int INF=~(1<<31),MOD=1e9+7;
#define lowbit(x) x&-x

struct Edge
{
    ll u,v;
}e[MAXN];

ll loc[MAXN],x[MAXN],y[MAXN],c[MAXN],k[MAXN];
ll dis[MAXN][MAXN],cnt;
ll d[MAXN],vis[MAXN],n,pt[MAXN];

ll prim()
{
    memset(d,0x3f,sizeof(d));
    d[0]=0;
    ll ans=0;
    vis[0]=1;
    for(int i=1;i<=n;i++)d[i]=min(d[i],dis[0][i]);
    for(int kase=1;kase<=n;kase++)
    {
        ll minn=llINF,now=0;
        for(int i=0;i<=n;i++)
            {if(!vis[i]&&minn>d[i])
        {
            minn=d[i];
            now=i;
        }}
        vis[now]=1;
        ans+=minn;
        if(now!=0&&pt[now]!=0)
        e[++cnt]={now,pt[now]};
        else loc[now]=loc[max(now,pt[now])]=1;
        for(int i=0;i<=n;i++)
        {
            if(now!=i&&d[i]>dis[now][i]&&!vis[i])
            {
                d[i]=dis[now][i];
                pt[i]=now;
            }
        }
    }
    return ans;
}

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&k[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if(i!=j)
        dis[i][j]=dis[j][i]=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
    for(int i=1;i<=n;i++)
        dis[0][i]=dis[i][0]=c[i];
    ll ans=prim();
    printf("%lld\n",ans);
    ans=0;
    for(int i=1;i<=n;i++)if(loc[i])ans++;
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++)if(loc[i])printf("%d ",i);
    printf("\n%lld\n",cnt);
    for(int i=1;i<=cnt;i++)
        printf("%lld %lld\n",e[i].u,e[i].v);
    return 0;
}
