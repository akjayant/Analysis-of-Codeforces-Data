#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const ll inf=1e16;
const int maxn=1e5+5;
int n; ll c[4][maxn];
vector<int>g[maxn];  int res[maxn];
int size[maxn]; int nxt[maxn];
void dfs(int u, int fa){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i]; if(v==fa) continue;
        dfs(v,u); nxt[u]=v;size[u]++;
    }
}
bool check(int u){
    dfs(u,-1);
    for(int i=1;i<=n;i++) if(size[i]>=2) return false;
    return true;
}
ll solve(int u, int x, int y){
    res[u]=x; res[nxt[u]]=y;
    ll ans=c[x][u]+c[y][nxt[u]]; u=nxt[u]; u=nxt[u];
    while(u){
        for(int i=1;i<=3;i++){
            if(i==x||i==y) continue;
            ans+=c[i][u]; res[u]=i; x=y; y=i; break;
        }
        u=nxt[u];
    }
    return ans;
}
int deg[maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=3;i++) for(int j=1;j<=n;j++) scanf("%lld",&c[i][j]); int u, v;
    for(int i=1;i<=n-1;i++) scanf("%d%d",&u,&v), g[u].push_back(v), g[v].push_back(u), deg[u]++, deg[v]++;
    if(n==1) printf("%lld\n",min(c[1][1],min(c[2][1],c[3][1])));
    ll ans=inf;
    for(int i=1;i<=n;i++) {
        if(deg[i]==1){
            if(!check(i)) return !printf("-1\n");
            for(int j=1;j<=3;j++) for(int k=1;k<=3;k++){
                if(j!=k) ans=min(ans,solve(i,j,k));
            }
            for(int j=1;j<=3;j++) for(int k=1;k<=3;k++){
                if(j!=k){
                    if(ans==solve(i,j,k)){
                        printf("%lld\n",ans);
                        for(int p=1;p<=n;p++) printf("%d ",res[p]);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
