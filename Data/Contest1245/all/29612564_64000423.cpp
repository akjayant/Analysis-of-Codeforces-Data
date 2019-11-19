#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=2010;
int n,c[N],d[N],id[N];
int r(int x) {return id[x]<0?x:id[x]=r(id[x]);}
bool join(int u,int v)
{
    if((u=r(u))==(v=r(v))) return 0;
    id[u]+=id[v];
    id[v]=u;
    return 1;
}
pii a[N];
struct oo {int u,v,c;};
vector<oo> e;
bool cmp(oo u,oo v) {return u.c<v.c;}
vector<int> e1;
vector<pii> e2;
main()
{
    //freopen("1245D.inp","r",stdin);
    reset(id,-1);
    n=in;
    forinc(i,1,n) a[i]={in,in};
    forinc(i,1,n) c[i]=in,e.pb({0,i,c[i]});
    forinc(i,1,n)
    {
        d[i]=in;
        forinc(j,1,i-1) e.pb({i,j,(d[i]+d[j])*(abs(a[i].fi-a[j].fi)+abs(a[i].se-a[j].se))});
    }
    sort(all(e),cmp);
    int ans=0;
    forv(x,e) if(join(x.u,x.v))
    {
        ans+=x.c;
        if(x.u==0) e1.pb(x.v);
        else e2.pb({x.u,x.v});
    }
    cout<<ans<<"\n";
    cout<<e1.size()<<"\n";
    forv(x,e1) cout<<x<<" ";cout<<"\n";
    cout<<e2.size()<<"\n";
    forv(x,e2) cout<<x.fi<<" "<<x.se<<"\n";
}
