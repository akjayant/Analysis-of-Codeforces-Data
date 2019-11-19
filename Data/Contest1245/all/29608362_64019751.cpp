/*   Author : Rshs
 *   Data : 2019-11-01-23.21
 */
#include<bits/stdc++.h>
using namespace std;
#define FI first
#define SE second
#define LL long long
#define MP make_pair
#define PII pair<int,int>
#define SZ(a) (int)a.size()
const double pai = acos(-1);
const double eps = 1e-10;
const LL mod = 1e9+7;
const int MXN = 1e6+5;
int x[MXN],y[MXN],c[MXN],k[MXN];
LL dis(int u,int v){
    LL z= abs(x[u]-x[v])+abs(y[u]-y[v]);
    return z*(LL)(k[u]+k[v]);
}
struct no{
    LL x,y,c;
};
bool operator<(const no &x,const no &y){
    return x.c<y.c;
}
vector<no>v;
int fa[MXN];
int found(int x){
    if(fa[x]==x)return x;
    return fa[x]=found(fa[x]);
}
vector<int>ans1;
vector<PII>ans2;
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)scanf("%d",&k[i]);
    for(int i=1;i<=n;i++){
        v.push_back(no{0,i,c[i]});
        v.push_back(no{i,0,c[i]});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            v.push_back(no{i,j,dis(i,j)});
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<=n;i++) fa[i]=i;
    LL ans=0;
    for(auto i:v){
        int fx=found(i.x),fy=found(i.y);
        if(fx==fy) continue;
        fa[fx]=fa[fy];
        ans+=i.c;
        if(i.x==0) {ans1.push_back(i.y);continue;}
        if(i.y==0) {ans1.push_back(i.x);continue;}
        ans2.push_back(MP(i.x,i.y));
    }
    cout<<ans<<'\n';
    cout<<SZ(ans1)<<'\n';
    for(auto i:ans1) cout<<i<<' ';
    puts("");
    cout<<SZ(ans2)<<'\n';
    for(auto i:ans2) cout<<i.FI<<' '<<i.SE<<'\n';
    return 0;
}
