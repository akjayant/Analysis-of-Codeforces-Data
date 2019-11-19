#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
typedef long long ll;
int a[N],b[N],c[N],deg[N],vis[N],n;
vector<int>g[N],v[5];

void dfs(int s,int x)
{
//    printf("%d ",s);
    vis[s]=x;v[x].push_back(s);
    for (auto t:g[s])
    {
        if(!vis[t]) dfs(t,x%3+1);
    }
}
ll f(int a[],int b[],int c[])
{
    ll ans=0;
    for (auto t:v[1]) ans+=a[t];
    for (auto t:v[2]) ans+=b[t];
    for (auto t:v[3]) ans+=c[t];
    return ans;
}
void output(int a,int b,int c)
{
    for (auto t:v[1]) vis[t]=a;
    for (auto t:v[2]) vis[t]=b;
    for (auto t:v[3]) vis[t]=c;
    for (int i=1;i<=n;i++) printf("%d ",vis[i]);
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",a+i);
    for (int i=1;i<=n;i++) scanf("%d",b+i);
    for (int i=1;i<=n;i++) scanf("%d",c+i);
    int u,v,s;
    for (int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        deg[u]++;deg[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
    {
        if(deg[i]==1) s=i;
        if(deg[i]>2)
        {
            printf("-1\n");
            return 0;
        }
    }
    dfs(s,1);
    ll ans=1e18,t,cas;
    if((t=f(a,b,c))<ans) ans= t,cas=1;
    if((t=f(a,c,b))<ans) ans= t,cas=2;
    if((t=f(b,a,c))<ans) ans= t,cas=3;
    if((t=f(b,c,a))<ans) ans= t,cas=4;
    if((t=f(c,a,b))<ans) ans= t,cas=5;
    if((t=f(c,b,a))<ans) ans= t,cas=6;
    printf("%lld\n",ans);
    if(cas==1) output(1,2,3);
    if(cas==2) output(1,3,2);
    if(cas==3) output(2,1,3);
    if(cas==4) output(2,3,1);
    if(cas==5) output(3,1,2);
    if(cas==6) output(3,2,1);
    return 0;
}
