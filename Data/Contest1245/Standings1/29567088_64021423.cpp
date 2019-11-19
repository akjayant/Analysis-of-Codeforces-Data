#include<bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int N=5e6+10;
const ll mod=1e9+7;
struct Edge{
    int a,b;
    ll w;
    Edge(){}
    Edge(int a,int b,ll w):a(a),b(b),w(w){}
    bool operator < (const Edge &o)const
    {
        return w<o.w;
    }
}e[N];
int book[N];
int c[2005],k[2005],x[2005],y[2005];
int father[N];
void init(int n)
{
    for(int i=0;i<=n;++i) father[i]=i;
}
int Find(int x)
{
    if(x==father[x]) return x;
    return father[x]=Find(father[x]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d%d",x+i,y+i);
    for(int i=1;i<=n;++i)
        scanf("%d",c+i);
    for(int i=1;i<=n;++i)
        scanf("%d",k+i);
    int tol=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j)
        {
            ll w=abs(x[i]-x[j])+abs(y[i]-y[j]);
            w*=(long long )(k[i]+k[j]);
            e[tol++]=Edge(i,j,w);
        }
    }
    for(int i=1;i<=n;++i)
    {
        e[tol++]=Edge(0,i,(long long )c[i]);
    }
    sort(e,e+tol);
    long long sum=0;
    init(n);
    for(int i=0;i<tol;++i)
    {
        int fa=Find(e[i].a),fb=Find(e[i].b);
        if(fa!=fb)
        {
            father[fa]=fb;
            book[i]=1;
            sum+=e[i].w;
        }
    }
    printf("%lld\n",sum);
    vector<int> pt1;
    int cnt1=0,cnt2=0;
    for(int i=0;i<tol;++i)
    {
        if(book[i]&&e[i].a==0)
            pt1.push_back(e[i].b);
    }
    printf("%d\n",(int)pt1.size());
    for(int v:pt1)
        printf("%d ",v);
    printf("\n");
    int m=n-(int)pt1.size();
    printf("%d\n",m);
    for(int i=0;i<tol;++i)
    {
        if(book[i]&&e[i].a!=0)
            printf("%d %d\n",e[i].a,e[i].b);
    }
    return 0;
}
