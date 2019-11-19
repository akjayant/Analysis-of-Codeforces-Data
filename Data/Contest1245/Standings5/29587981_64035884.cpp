#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 2007
#define NN 4002007
#define fi first
#define se second

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

struct gg
{
    int x,y;
};
gg a[N];
int n, c[N], k[N], p[N], d[N], cnt=0, maxx=0;
iii t[NN];
int ans=0, ans1=0, ans2=0, trace[N];
ii trace2[NN];

int root(int x)
{
    if (p[x]==x) return x;
    return p[x]=root(p[x]);
}

int join(int x,int y)
{
    return p[root(x)]=root(y);
}

#define task "BANGNHAC"

main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) scanf("%lld%lld",&a[i].x,&a[i].y);
    for(int i=1; i<=n; ++i) { scanf("%lld",&c[i]); maxx=max(maxx,c[i]); }
    for(int i=1; i<=n; ++i) scanf("%lld",&k[i]);
    for(int i=1; i<=n; ++i) { p[i]=i; d[i]=0;}
    for(int i=1; i<=n; ++i) t[++cnt]=iii(c[i],ii(0,i));
    for(int i=1; i<n; ++i)
        for(int j=i+1; j<=n; ++j)
        {
            int tmp=(k[i]+k[j])*(abs(a[i].x-a[j].x) + abs(a[i].y-a[j].y));
            if (tmp<maxx) t[++cnt]=iii(tmp,ii(i,j));
        }
    sort(t+1,t+cnt+1);
    for(int i=1; i<=cnt; ++i)
    {
        int w=t[i].fi, u=t[i].se.fi, v=t[i].se.se;
        if (u==0)
        {
            int h=root(v);
            if (d[h]==0)
            {
                d[h]=w;
                ans+=w;
                trace[++ans1]=v;
            }
        }
        else
        {
            int h=root(u), k=root(v);
            if (h==k) continue;
            if (d[h]!=0 && d[k]!=0) continue;
            if (d[h]==0 && d[k]==0)
            {
                join(h,k);
                ans+=w;
                trace2[++ans2]=ii(u,v);
                continue;
            }
            if (d[h]!=0)
            {
                join(k,h); d[k]=d[h];
                ans+=w;
                trace2[++ans2]=ii(u,v);
            }
            else if (d[k]!=0)
            {
                join(h,k); d[h]=d[k];
                ans+=w;
                trace2[++ans2]=ii(u,v);
            }
        }
    }
    cout<<ans<<endl;
    cout<<ans1<<endl;
    for(int i=1; i<=ans1; ++i) printf("%lld ",trace[i]); cout<<endl;
    cout<<ans2<<endl;
    for(int i=1; i<=ans2; ++i) printf("%lld %lld\n",trace2[i].fi,trace2[i].se);
}
