#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<set>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dwn(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
int n,tot=0,par[2010],x[2010],y[2010],k[2010],ansp[2010],cnt=0,ansx[2010],ansy[2010];
ll ans=0;
struct EDGE
{
    int x,y;
    ll d;
}a[6000010];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
bool cmp(EDGE a,EDGE b)
{
    return a.d<b.d;
}
int find(int x)
{
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
int main()
{
    n=read();
    rep(i,0,n) par[i]=i;
    rep(i,1,n) x[i]=read(),y[i]=read();
    rep(i,1,n)
    {
        int c=read();
        a[++tot].x=0,a[tot].y=i,a[tot].d=c;
    }
    rep(i,1,n)
    {
        k[i]=read();
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            a[++tot].x=i,a[tot].y=j;
            a[tot].d=(ll)(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
        }
    }
    sort(a+1,a+tot+1,cmp);
    for(int i=1;i<=tot;++i)
    {
        int x=find(a[i].x),y=find(a[i].y);
        if(x==y) continue;
        par[x]=y;
        ans+=a[i].d;
        if(a[i].x==0) ansp[++ansp[0]]=a[i].y;
        else ansx[++cnt]=a[i].x,ansy[cnt]=a[i].y;
    }
    printf("%I64d\n%d\n",ans,ansp[0]);
    for(int i=1;i<=ansp[0];++i)
    {
        printf("%d ",ansp[i]);
    }
    printf("\n%d\n",cnt);
    for(int i=1;i<=cnt;++i)
    {
        printf("%d %d\n",ansx[i],ansy[i]);
    }
    return 0;
}
