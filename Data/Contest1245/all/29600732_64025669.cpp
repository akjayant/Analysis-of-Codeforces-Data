#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int MAX_N=2000+5;

struct edge{
    int u,v;
    ll w;
    edge(){}
    edge(int ui,int vi,ll wi):u(ui),v(vi),w(wi){}
};

int n;
int X[MAX_N+1],Y[MAX_N+1];
int C[MAX_N+1],K[MAX_N+1];

int m;
edge es[MAX_N*MAX_N+MAX_N+1];
int par[MAX_N+1];

int res_n[MAX_N+1];
P res_m[MAX_N*MAX_N+1];

bool cmp1(edge A,edge B){
    return A.w<B.w;
}

void init(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ll w=((ll)K[i]+K[j])*((ll)abs(X[i]-X[j])+abs(Y[i]-Y[j]));
            es[++m]=edge(i,j,w);
        }
    }
    for(int i=1;i<=n;i++){
        es[++m]=edge(0,i,C[i]);
    }
    sort(es+1,es+m+1,cmp1);
    for(int i=0;i<=n;i++)par[i]=i;
}

int find(int x){
    if(x==par[x])return x;
    return par[x]=find(par[x]);
}

bool same(int x,int y){
    return find(x)==find(y);
}
void unite(int x,int y){
    x=find(x);y=find(y);
    par[x]=y;
}

void solve(){
    init();
    ll res=0;
    int ans1=0,ans2=0;
    for(int i=1;i<=m;i++){
        int u=es[i].u,v=es[i].v;
        if(!same(u,v)){
            unite(u,v);
            res+=es[i].w;
            //cout<<u<<" "<<v<<" "<<es[i].w<<"s"<<endl;
            if(u!=0&&v!=0)res_m[++ans2]=P(u,v);
            else res_n[++ans1]=u==0?v:u;
        }
    }
    printf("%I64d\n",res);
    printf("%d\n",ans1);
    for(int i=1;i<=ans1;i++)printf("%d%c",res_n[i],i==ans1?'\n':' ');
    printf("%d\n",ans2);
    for(int i=1;i<=ans2;i++)printf("%d %d\n",res_m[i].first,res_m[i].second);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",X+i,Y+i);
    for(int i=1;i<=n;i++)scanf("%d",C+i);
    for(int i=1;i<=n;i++)scanf("%d",K+i);
    solve();
    return 0;
}