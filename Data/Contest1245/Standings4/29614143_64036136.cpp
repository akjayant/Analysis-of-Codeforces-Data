#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx=1e5+10;
struct node{
    int x,y;  ll val;
    bool operator < (const node &a) const{
        return val<a.val;
    }
}b[maxx],c[maxx*40];
vector<node> Ans;
ll v[maxx],w[maxx];
int par[maxx];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&b[i].x,&b[i].y);
        par[i]=i;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
        ans+=v[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            ll x=1ll*(abs(b[i].x-b[j].x)+abs(b[j].y-b[i].y))*(w[i]+w[j]);
            c[++cnt]=node{i,j,x};
        }
    }
    sort(c+1,c+cnt+1);
    for(int i=1;i<=cnt;i++){
        int fx,fy; fx=find(c[i].x); fy=find(c[i].y);
        if(fx==fy) continue;
        if(c[i].val<max(v[fx],v[fy])){
            ans-=max(v[fx],v[fy]);
            ans+=c[i].val;
            if(v[fx]<v[fy]) par[fy]=fx;
            else par[fx]=fy;
            Ans.push_back(node{c[i].x,c[i].y});
        }
    }
    cout<<ans<<endl;
    vector<int> Res;
    for(int i=1;i<=n;i++){
        if(par[i]==i) Res.push_back(i);
    }
    cout<<Res.size()<<endl;
    for(auto x:Res){
        cout<<x<<" ";
    }
    puts("");
    cout<<Ans.size()<<endl;
    for(auto x:Ans){
        cout<<x.x<<" "<<x.y<<endl;
    }
}
