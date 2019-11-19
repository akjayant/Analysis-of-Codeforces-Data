//    KHAz
#include <bits/stdc++.h>
#define maxn 2005
#define Task ""
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define pii pair< int , int >
#define reset(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
int n,dem,par[maxn],m,m1,m2,d1[maxn];
pii a[maxn],d2[maxn];
vector<pii> res;
struct data
{
    int u ,v ;
    long long w;
} b[maxn*maxn];
ll ans;
int get(int u)
{
    if(par[u]==u) return u;
    return par[u]=get(par[u]);
}
bool cmp(data x ,data y)
{
    return x.w<y.w;
}
long long c[maxn][maxn],p[maxn],k[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
  //  freopen(Task".inp","r",stdin);
   // freopen(Task".out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].F>>a[i].S,par[i]=i;
    for(int i=1;i<=n;i++) cin>>p[i],b[++m]={0,i,p[i]};
    for(int i=1;i<=n;i++) cin>>k[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            long long x=(k[i]+k[j])*(abs(a[i].F-a[j].F)+abs(a[i].S-a[j].S));
            b[++m]={i,j,x};
        }
    }
    sort(b+1,b+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int u=b[i].u , v=b[i].v;
        int p=get(u),q=get(v);
        if(p==q) continue;
        par[p]=q;
        ans+=b[i].w;
        res.PB({u,v});
        dem++;
        if(dem==n) break;
    }
    cout << ans<<endl;
    for(auto cc:res)
    {
        int x=cc.F , y=cc.S;
        if(x==0)
        {
            d1[++m1]=y;
        }
        else
        {
            d2[++m2]={x,y};
        }
    }
    cout <<m1<<endl;
    for(int i=1;i<=m1;i++) cout << d1[i]<<' ';
    cout <<endl<<m2<<endl;
    for(int i=1;i<=m2;i++)
    {
        cout << d2[i].F<<' '<<d2[i].S<<endl;
    }
    return 0;
}
