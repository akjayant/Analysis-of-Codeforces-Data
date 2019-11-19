#include <bits/stdc++.h>
using namespace std;

const int N=2005;
typedef long long ll;
ll k[N],dis[N],ans;
int x[N],y[N],n,fa[N];
bool vis[N];
vector<int>v1;
vector<pair<int,int> >v2;

void prim()
{
    int v;
    for (int i=1;i<=n;i++)
    {
        ll m=1e18;
        for (int j=1;j<=n;j++)
            if(!vis[j]&&m>dis[j]) m=dis[v=j];
        vis[v]=1;ans+=dis[v];
        if(fa[v]) v2.push_back({v,fa[v]});
        else v1.push_back(v);
        for (int j=1;j<=n;j++)
        {
            if(!vis[j]&&(abs(x[j]-x[v])+abs(y[j]-y[v]))*(k[j]+k[v])<dis[j])
            {
                dis[j]=(abs(x[j]-x[v])+abs(y[j]-y[v]))*(k[j]+k[v]);
                fa[j]=v;
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",x+i,y+i);
    for (int i=1;i<=n;i++) scanf("%lld",dis+i);
    for (int i=1;i<=n;i++) scanf("%lld",k+i);
    prim();
    printf("%lld\n",ans);
    printf("%d\n",v1.size());
    for (auto it:v1) printf("%d ",it);
    printf("\n");
    printf("%d\n",v2.size());
    for (auto it:v2) printf("%d %d\n",it.first,it.second);
    return 0;
}
