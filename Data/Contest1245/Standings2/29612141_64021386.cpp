#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=2e3+5;
int se[N],mn[N];
int get(int x){return x==se[x]?x:se[x]=get(se[x]);}

struct node{
    int u,v;
    ll w;
    bool operator<(const node&a)const{
        return w<a.w;
    }
}e[N*N];
int c[N],k[N];
int x[N],y[N];
int dis(int i,int j){
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
vector<int>id;
vector<pii>edge;

void init();
void work();
int ca=1;
int main(){
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
//    init();
//    int T;cin>>T;
//    while(T--)
    work();
    return 0;
}
void work(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    ll sum=0;
    for(int i=1;i<=n;i++) cin>>c[i],sum+=c[i],se[i]=i,mn[i]=c[i];
    for(int i=1;i<=n;i++) cin>>k[i];
    int ct=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            e[++ct]=node{i,j,1LL*(k[i]+k[j])*dis(i,j)};
        }
    }
    sort(e+1,e+ct+1);
//    for(int i=1;i<=ct;i++) cout<<"w: "<<e[i].w<<endl;
    ll ans=sum;
    for(int i=1;i<=ct;i++){
        int fu=get(e[i].u),fv=get(e[i].v);
        if(fu==fv) continue;
        if(e[i].w>=max(mn[fu],mn[fv])) continue;
        if(mn[fu]<mn[fv]) swap(fu,fv);
        ans-=mn[fu];
        ans+=e[i].w;
        se[fu]=fv;
        edge.push_back(pii(e[i].u,e[i].v));
    }
    for(int i=1;i<=n;i++)if(get(i)==i)id.push_back(i);
    cout<<ans<<'\n';
    cout<<id.size()<<'\n';
    for(auto x:id) cout<<x<<' ';
    cout<<'\n';
    cout<<edge.size()<<'\n';
    for(auto p:edge) cout<<p.first<<' '<<p.second<<'\n';
}
