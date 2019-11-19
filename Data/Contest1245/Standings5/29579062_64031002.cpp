#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
void read(int&x)
{
    x=0;char c;
    do{c=getchar();}while(c<'0'||c>'9');
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
#define MAXN 2000
#define MAXM 4400000
struct node
{
    int u,v;
    long long w;
    friend bool operator<(node a,node b){return a.w<b.w;}
    node(int a=0,int b=0,long long c=0){u=a;v=b;w=c;}
}e[MAXM+5];
int en,f[MAXN+5],x[MAXN+5],y[MAXN+5],k[MAXN+5];
int gf(int K){return f[K]==K?K:f[K]=gf(f[K]);}
int av[MAXN+5],ax[MAXN+5],ay[MAXN+5],cv,cn;
int main()
{
    int n,i,j,w;
    long long ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w);
        e[en++]=node(0,i,1ll*w);
    }
    for(i=1;i<=n;i++) scanf("%d",&k[i]);
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            long long cos=1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
            e[en++]=node(i,j,cos);
        }
    }
    sort(e,e+en);
    for(i=1;i<=n;i++)f[i]=i;
    for(i=0,j=0;i<n;i++,j++)
    {
        for(;gf(e[j].u)==gf(e[j].v);j++);
        f[gf(e[j].u)]=gf(e[j].v);
        ans+=e[j].w;
        if(e[j].u==0) av[++cv]=e[j].v;
        if(e[j].v==0) av[++cv]=e[j].u;
        if(e[j].u!=0&&e[j].v!=0) ax[++cn]=e[j].u,ay[cn]=e[j].v; 
    }
    printf("%I64d\n",ans);sort(av+1,av+cv+1);
    printf("%d\n",cv);
    for(i=1;i<=cv;i++) printf("%d ",av[i]);puts("");
    printf("%d\n",cn);
    for(i=1;i<=cn;i++) printf("%d %d\n",ax[i],ay[i]);
    return 0;
}