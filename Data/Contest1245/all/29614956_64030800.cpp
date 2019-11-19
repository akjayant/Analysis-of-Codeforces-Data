#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
#define ls root<<1
#define rs root<<1|1
using namespace std;
const int maxn=3e6+7;
const int maxm=2100;
const double eps=1e-6;
typedef long long ll;
ll n,x[maxm],y[maxm],c[maxm],k[maxm],s,cnt,fa[maxm],res,tot,head[maxn];
struct edge
{
    ll v,w,next;
}e[maxn];
vector<ll> v;
vector<pair<ll,ll> >g;
struct node{
    ll u,v,w;
}t[maxn];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
ll dis(int i,int j)
{
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
void add(int a,int b,int c)
{
    e[++tot]=edge{b,c,head[a]};
    head[a]=tot;
}
ll findfa(int x)
{
    return x==fa[x]?x:fa[x]=findfa(fa[x]);
}
void mst()
{
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    sort(t+1,t+1+cnt,cmp);
    for(int i=1;i<=cnt;i++){
        int ta=findfa(t[i].u);
        int tb=findfa(t[i].v);
        if(ta!=tb){
            fa[ta]=tb;
            res+=t[i].w;
            if(t[i].u==s || t[i].v==s)v.push_back(t[i].u+t[i].v);
            else  g.push_back({t[i].u,t[i].v});
        }
    }
}
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",x+i,y+i);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",c+i);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",k+i);
    }
    for(int i=1;i<=n;i++){
        t[++cnt]=node{s,i,c[i]};
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            t[++cnt]=node{i,j,(k[i]+k[j])*dis(i,j)};
        }
    }
    mst();
    cout<<res<<endl;
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
    cout<<g.size()<<endl;
    for(int i=0;i<g.size();i++){
        cout<<g[i].first<<' '<<g[i].second<<endl;
    }
    return 0;
}
