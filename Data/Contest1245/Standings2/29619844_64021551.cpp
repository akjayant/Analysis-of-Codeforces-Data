#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=2e3+10;
ll x[mn],y[mn],c[mn],k[mn];
int p[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
vector<pair<ll,pii>> h;
int main(){
    int n;
    scanf("%d",&n);
    iota(p,p+n+1,0);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",x+i,y+i);
    }
    for(int i=1;i<=n;i++)scanf("%lld",c+i);
    for(int i=1;i<=n;i++)scanf("%lld",k+i);
    for(int i=1;i<=n;i++)h.push_back({c[i],{0,i}});
    for(int i=1;i<=n;i++)for(int j=1;j<i;j++){
        h.push_back({(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])),{i,j}});
    }
    sort(h.begin(),h.end());
    ll ans=0;
    vector<int>aaa,bbb,ccc;
    for(auto hail:h){
        int a=hail.second.first,b=hail.second.second;
        ll w=hail.first;
        if(f(a)!=f(b)){
            ans+=w,p[f(a)]=f(b);
            if(a==0)aaa.push_back(b);
            else bbb.push_back(a),ccc.push_back(b);
        }
    }
    printf("%lld\n",ans);
    printf("%d\n",aaa.size());
    for(int hhh:aaa)printf("%d ",hhh);
    printf("\n%d\n",bbb.size());
    for(int i=0;i<bbb.size();i++){
        printf("%d %d\n",bbb[i],ccc[i]);
    }
}