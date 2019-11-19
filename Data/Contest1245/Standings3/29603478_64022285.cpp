#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=4e6+10,mod=1e9+7;
ll x[N],y[N],c[N],k[N],as;
struct sc
{
    ll a,b,c;
    bool operator<(const sc &t)const
    {
        return t.c>c;
    }
} p[N];
int pp[N];
int f(int x)
{
    if(x==pp[x])return x;
    return pp[x]=f(pp[x]);
}
void U(int a,int b)
{
    int x=f(a),y=f(b);
    if(c[x]<c[y])pp[y]=x;
    else pp[x]=y;
    //c[x]=c[y]=min(c[x],c[y]);
}
vector<int>aa;
int main()
{
  //  freopen("i.txt","r",stdin);
    ll n,m=0;
    scanf("%lld",&n);
    for(int i=1; i<=n; i++)scanf("%lld %lld",&x[i],&y[i]),pp[i]=i;
    for(int i=1; i<=n; i++)scanf("%lld ",&c[i]);
    for(int i=1; i<=n; i++)scanf("%lld ",&k[i]);
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            ll t=abs(x[j]-x[i])+abs(y[j]-y[i]);
            p[m++]= {i,j,t*(k[i]+k[j])};
        }
    }
    sort(p,p+m);
    for(int i=0; i<m; i++)
    {
        ll u=p[i].a,v=p[i].b,w=p[i].c;
        if(f(u)==f(v))continue;
        if(c[f(u)]<w&&c[f(v)]<w)continue;
        U(v,u);
        as+=w;
        //cout<<w<<endl;
        aa.push_back(i);
    }
    int cc=0;
    for(int i=1; i<=n; i++)if(f(i)==i)as+=c[i],cc++;
    printf("%lld\n",as);
    printf("%d\n",cc);
    for(int i=1; i<=n; i++)if(f(i)==i)printf("%d ",i);
    puts("");
    printf("%d\n",aa.size());
    for(int i:aa)
        printf("%lld %lld\n",p[i].a,p[i].b);
}
