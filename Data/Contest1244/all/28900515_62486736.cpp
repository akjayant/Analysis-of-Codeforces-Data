#include<bits/stdc++.h>
#define rep(i,b,e) for(LL i=(b);i<(e);++i)
#define dep(i,b,e) for(LL i=(b);i>=(e);--i)
#define LL long long

using namespace std;

int n,u,v,c[3][100001];
int d[100001],a[100001];
vector<int> g[100001];
int b[100001];

int ls(int a,int b){
    if(a>b) swap(a,b);
    if(a==0){
        if(b==1) return 2;
        else return 1;
    }
    else return 0;
}

LL dp(int x,int y){
    LL rt=c[x][a[1]]+c[y][a[2]];
    int z;
    rep(i,3,n+1){
        z=ls(x,y);
        rt+=c[z][a[i]];
        x=y;y=z;
    }
    return rt;
}

void dfs(int nd,int fa,int id){
    a[id]=nd;
    for(auto &t:g[nd]){
        if(t!=fa) dfs(t,nd,id+1);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;memset(d,0,sizeof(d));
    rep(i,0,3){
        rep(j,1,n+1) cin>>c[i][j];
    }
    rep(i,0,n-1){
        cin>>u>>v;
        d[u]++;d[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i,1,n+1){
        if(d[i]>2){cout<<-1<<endl;return 0;}
        if(d[i]==1) u=i;
    }
    dfs(u,0,1);LL ans=1e18,ap;
    rep(i,0,3){
        rep(j,0,3){
            if(i==j) continue;
            if((ap=dp(i,j))<ans){
                u=i;v=j;ans=ap;
            }
        }
    }
    cout<<ans<<endl;
    b[a[1]]=u;b[a[2]]=v;int w;
    rep(i,3,n+1){
        w=ls(u,v);
        b[a[i]]=w;
        u=v;v=w;
    }
    rep(i,1,n+1) cout<<b[i]+1<<' ';
    cout<<endl;
    //system("pause");
    return 0;
}
