#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 300005
#define ll long long
int n;
int w[N];
ll p[3][N];
ll sum;  ll ans=0x3f3f3f3f3f3f3f3f; int son_color; int rt;
int cnt; int head[N]; int color[N];
struct edge{
    int des; int next;
}e[N<<1];

void ins(int u,int v){
    ++cnt; e[cnt].des=v; e[cnt].next=head[u]; head[u]=cnt;
}

void dfs(int u,int f,int ff){
    if(color[u]!=-1){
        sum+=p[color[u]][u];
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].des;
            if(v==f) continue;
            dfs(v,u,f);
        }
        return;
    }
    if(f!=-1&&ff==-1){
        color[u]=3-color[rt]-son_color;
        sum+=p[color[u]][u];
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].des;
            if(v==f) continue;
            dfs(v,u,f);
        }
        return;
    }
    if(f!=-1&&ff!=-1){
        color[u]=3-color[f]-color[ff];
        sum+=p[color[u]][u];
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].des;
            if(v==f) continue;
            dfs(v,u,f);
        }
        return;
    }
}

int res[N];


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%lld",&p[0][i]);
    for(int i=1;i<=n;++i) scanf("%lld",&p[1][i]);
    for(int i=1;i<=n;++i) scanf("%lld",&p[2][i]);
    for(int i=1;i<n;++i){
        int u; int v;
        scanf("%d %d",&u,&v);
        ++w[u]; ++w[v];  ins(u,v);  ins(v,u);
    }
    for(int i=1;i<=n;++i){
        if(w[i]>2){
            printf("-1\n");
            return 0;
        }
    }
    rt=1;
    for(int i=0;i<3;++i){  //枚举根的颜色
        for(int j=0;j<3;++j){ //枚举根的第一个儿子的颜色
            if(j==i) continue;   son_color=j;
            memset(color, -1, sizeof(color));  color[rt]=i;  color[e[head[rt]].des]=j;
            sum=0;  dfs(rt,-1,-1);
            if(sum<ans){
                ans=sum;
                for(int i=1;i<=n;++i) res[i]=color[i];
            }
        }
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;++i) printf("%d ",res[i]+1); printf("\n");
    return 0;
}







