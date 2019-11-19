#include <bits/stdc++.h>
#define N 100005
#define P pair<ll,ll>
#define fi first
#define sc second
typedef long long ll;
using namespace std;

struct Point{
    ll x,y,w,k,id;
    bool operator <(const Point &t){
        return w<t.w;
    }
}p[N];

ll fa[N],dp[N],now,ans=0;

struct Edge{
    ll x,y,w;
    bool operator <(const Edge &t)const{
        return w<t.w;
    }
}e[2000005];


ll findd(ll x){
    if(x==fa[x]){
        return x;
    }else {
        return fa[x]=findd(fa[x]);
    }
}

ll add(ll x,ll y){
    if(dp[x]<dp[y]){
        fa[y]=x;
    }else{
        fa[x]=y;
    }
}
vector<ll> v;
vector<P> vv;


int main(){
    ll n,cnt=0;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld%lld",&p[i].x,&p[i].y); p[i].id=i;
    }
    for(ll i=1;i<=n;i++) scanf("%lld",&p[i].w);
    for(ll i=1;i<=n;i++) scanf("%lld",&p[i].k);
    for(ll i=1;i<=n;i++){
        fa[i]=i; dp[i]=p[i].w; ans+=dp[i];
    }

    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            e[++cnt].x=i;
            e[cnt].y=j;
            e[cnt].w=(p[i].k+p[j].k)*(abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y));
        }
    }
    sort(e+1,e+cnt+1);
    for(ll i=1;i<=cnt;i++){
        ll fx=findd(e[i].x);
        ll fy=findd(e[i].y);
        if(fx==fy) continue;
        if(e[i].w<max(dp[fx],dp[fy])){
            ans-=max(dp[fx],dp[fy]);
            ans+=e[i].w;
            vv.push_back(P(e[i].x,e[i].y));
            add(fx,fy);
        }
    }
    for(ll i=1;i<=n;i++){
        if(findd(i)==i) v.push_back(i);
    }
    printf("%lld\n",ans);

    printf("%lld\n",(ll)v.size());
    for(auto x:v) printf("%lld ",x);
    puts("");

    printf("%lld\n",(ll)vv.size());
    for(auto now:vv) printf("%lld %lld\n",now.fi,now.sc);
    puts("");
}
