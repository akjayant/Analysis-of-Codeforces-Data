#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define maxn 2100
#define ll long long
using namespace std;

struct node
{ 
    int u,v;
    ll d;
    bool operator < (node rhs) const { return d<rhs.d; }
}p[2011000];
int fa[maxn],tot;
int n;
int x[maxn],y[maxn];
int k[maxn];
int s;
vector<int> ansp,ansn;
ll ans;
inline int getf(int u)
{
    return u==fa[u] ? u : fa[u]=getf(fa[u]);
}
inline bool merge(int u,int v)
{
    int t1=getf(u),t2=getf(v);
    if(t1==t2) return false;
    fa[t1]=t2;
    return true;
}
int main()
{
    scanf("%d",&n);s=n+1;
    for(register int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
    for(register int i=1;i<=n;i++)
    {
        int c;scanf("%d",&c);
        p[++tot]=(node) { i,s,(ll)c };
    }
    for(register int i=1;i<=n;i++) scanf("%d",&k[i]);
    for(register int i=1;i<=n;i++)
    {
        for(register int j=i+1;j<=n;j++)
            p[++tot]=(node) { i,j,(ll)(k[i]+k[j])*(ll)(abs(x[i]-x[j])+abs(y[i]-y[j]))};
    }
    sort(p+1,p+tot+1);
    for(register int i=1;i<=s;i++) fa[i]=i;
    int chose=0;
    for(register int i=1;i<=tot && chose<n;i++)
        if(merge(p[i].u,p[i].v))
        {
            chose++;
            ans+=p[i].d;
            if(p[i].v==s) ansp.push_back(p[i].u);
            else ansn.push_back(i);
        }

    printf("%lld\n",ans);
    printf("%d\n",ansp.size());
    for(register int i=0;i<ansp.size();i++) printf("%d ",ansp[i]);putchar('\n');
    printf("%d\n",ansn.size());
    for(register int i=0;i<ansn.size();i++) printf("%d %d\n",p[ansn[i]].u,p[ansn[i]].v);
    return 0;
}