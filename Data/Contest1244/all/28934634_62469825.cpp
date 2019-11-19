#include<iostream>
#include<cstdio>
#include<vector>
const int N=1e5+5;
int c[N],b[N];
int t[N],n,a[3][N],tail;
std::vector<int> g[N];
void dfs(int u,int fa) {
    t[++tail]=u;
    for(int v:g[u]) if(v!=fa) dfs(v,u);
}
long long work(int x,int y) {
    b[1]=x;b[2]=y;
    long long ans=a[x][t[1]]+a[y][t[2]];
    for(int i=3;i<=n;i++) {
        int mask=(1<<b[i-1])+(1<<b[i-2]);
        for(int j=0;j<3;j++) if(!(mask>>j&1)) {
            ans+=a[j][t[i]];
            b[i]=j;
            break;
        }
    }
    return ans;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<3;i++) for(int j=1;j<=n;j++) scanf("%d",a[i]+j);
    for(int i=1,u,v;i<n;i++) {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        if(g[i].size()>2) return !printf("-1");
    }
    tail=0;
    for(int i=1;i<=n;i++) if(g[i].size()==1) {
        dfs(i,0);
        break;
    }
    long long ans=1e18;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(i!=j) {
        long long res=work(i,j);
        if(res<ans) {
            ans=res;
            for(int k=1;k<=n;k++) {
                c[t[k]]=b[k]+1;
            }
        }
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++) printf("%d%c",c[i]," "[i==n]);
    return 0;
}
