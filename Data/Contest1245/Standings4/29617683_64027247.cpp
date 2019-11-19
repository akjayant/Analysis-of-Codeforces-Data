#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 200005
#define maxm 5000005
#define INF 1234567890
#define p 1000000007
template<class T>inline bool read(T &x)
{
    x=0;register char c=getchar();register bool f=0;
    while(!isdigit(c)){if(c==EOF)return false;f^=c=='-',c=getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
    if(f)x=-x;
    return true;
}
template<class T>inline void print(T x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10^48);
}
template<class T>inline void print(T x,char c){print(x),putchar(c);}
ll n,m,rt[maxn],rk[maxn],ans,cnt,x[maxn],y[maxn],k[maxn],res[maxn],res1[maxn],res2[maxn],tot,tot2;
struct Edge{ll u,v,w;}edge[maxm];
bool cmp(Edge x,Edge y){return x.w<y.w;}
void add(ll u,ll v,ll w)
{
    edge[++cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].w=w;
}
ll getr(ll x){return rt[x]==x?x:rt[x]=getr(rt[x]);}
void un(ll x,ll y)
{
    ll gx=getr(x),gy=getr(y);
    if(gx==gy)return;
    if(rk[gx]>rk[gy])
        rt[gy]=gx;
    else
    {
        rt[gx]=gy;
        if(rk[gx]==rk[gy])rk[gy]++;
    }
}
void Kruskal()
{
    sort(edge+1,edge+cnt+1,cmp);
    for(ll i=1;i<=cnt;i++)
    {
        ll u=edge[i].u,v=edge[i].v,w=edge[i].w;
        if(getr(u)==getr(v))continue;
        un(u,v);
        ans+=w;
        tot++;
        if(v&&u)
        {
            res1[tot]=u;
            res2[tot]=v;
        }
        else if(u)
        {
            res[++tot2]=u;
        }
        else if(v)
        {
            res[++tot2]=v;
        }
        if(tot==n+1)return;
    }
}
int main()
{
    //freopen("test.in","r",stdin);
    read(n);
    for(ll i=0;i<=n;i++)rt[i]=i;
    for(ll i=1;i<=n;i++)
        read(x[i]),read(y[i]);
    ll c,w;
    for(ll i=1;i<=n;i++)
    {
        read(c);
        add(0,i,c);
    }
    for(ll i=1;i<=n;i++)
        read(k[i]);
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
        {
            w=abs(x[i]-x[j])+abs(y[i]-y[j]);
            add(i,j,w*(k[i]+k[j]));
        }
    Kruskal();
    print(ans,'\n');
    sort(res+1,res+tot2+1);
    print(tot2,'\n');
    for(ll i=1;i<tot2;i++)
        print(res[i],' ');
    print(res[tot2],'\n');
    print(tot-tot2,'\n');
    for(ll i=1;i<=tot;i++)
    {
        if(!res1[i])continue;
        print(res1[i],' ');
        print(res2[i],'\n');
    }
    return 0;
}
