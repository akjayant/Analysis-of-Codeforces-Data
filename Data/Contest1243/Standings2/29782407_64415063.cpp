#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef double db;

#define mp make_pair
#define pb push_back
#define pt(i) printf("%lld\n",(ll)i)
#define mp make_pair
#define ff first
#define ss second
#define pi acos(-1.0)

ll in() { ll a;scanf("%lld",&a); return a;}
db din(){ db a;scanf("%lf",&a); return a; }
ll bigmod(ll b, ll p,ll md){if(p==0) return 1;if(p%2==1){ return ((b%md)*bigmod(b,p-1,md))%md;} else {ll y=bigmod(b,p/2,md);return (y*y)%md;}}
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b);}

long long getRandom(long long a,long long b){
    long long ret = (long long)rand()*(long long)rand();
    ret %= (b - a + 1);
    ret += a;
    return ret;
}

vi adj1[4000005],adj2[4000005];
int n,m,ac,par[100005];

map<pii,int> mpp;

int fi_par(int u)
{
    if(par[u]==u)
    return u;
    return par[u]=fi_par(par[u]);
}

void ad(int lev,int js,int st,int en,int l,int r)
{
    if(l>r)
    return ;
    if(l>en||r<st)
    return;
    if(l>=st&&r<=en)
    {

        int x=fi_par(js),y=fi_par(l),z=fi_par(r);
        par[x]=par[y]=z;
        if(mpp.find(pii(l,r))==mpp.end())
        for(int i=l;i<r;i++)
        {
            int x=fi_par(i),y=fi_par(i+1);
            par[x]=y;
        }
        mpp[pii(l,r)]=1;
        return;
    }
    int mid=(l+r)/2;
    ad(lev+1,js,st,en,l,mid);
    ad(lev+1,js,st,en,mid+1,r);


}

int vis[4000005];

int main()
{
    n=in(),m=in();
//    build(1,1,n);
    for(int i=0;i<=n;i++)
    par[i]=i;
    for(int i=0;i<m;i++)
    {
        int u=in();
        int v=in();
        adj1[u].pb(v);
        adj1[v].pb(u);
    }
    for(int i=1;i<=n;i++)
    adj1[i].pb(0),sort(adj1[i].begin(),adj1[i].end()),adj1[i].pb(n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<adj1[i].size()-1;j++)
        {
            int lst=adj1[i][j+1];
            ad(1,i,adj1[i][j]+1,lst-1,1,n);
        }
    }
    int cnt=0;
    int cnt2=0;
    for(int i=1;i<=n;i++)
    {
        if(par[i]==i)
        cnt2++;
    }

    pt(cnt2-1);
}

