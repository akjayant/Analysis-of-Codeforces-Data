/*Program from Luvwgyx*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int inf=1e18;
const int maxn=1e5+10;
struct edge{int to,nxt;}e[maxn<<1];
int n,tot,cnt,id[3],ansid[3],head[maxn],deg[maxn],lst[maxn],ans[maxn],c[3][maxn],f[maxn][3][3];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void write(int x){print(x);puts("");}
void add(int u,int v){e[++tot].to=v;e[tot].nxt=head[u];head[u]=tot;deg[v]++;}
void insert(int u,int v){add(u,v);add(v,u);}
/*
void init(){memset(f,63,sizeof(f));}
int f[3];
int get(int x,int y){
    memest(f,0,sizeof(f));
    f[x]=1;f[y]=1;int pos=0;
    for(int i=0;i<3;i++)if(!f[i]){pos=i;break;}
    return pos;
}
void dfs(int x,int fa){
    bool flag=0;
    for(int i=head[x],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
        if(v!=fa){
            flag=1;dfs(v,x);
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(j==k)continue;
                    int l=get(j,k);
                    f[x][j][k]=min(f[x][j][k],f[v][k][l]+c[j][x]);
                }
            }
        }
    if(!flag){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(i!=j)f[x][i][j]=c[i][x];
    }
}
*/
void dfs(int x,int fa){
    lst[++cnt]=x;
    for(int i=head[x],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
        if(v!=fa)dfs(v,x);
}
signed main(){
    n=read();int root=0;
    for(int i=0;i<3;i++)for(int j=1;j<=n;j++)c[i][j]=read();
    for(int i=1;i<n;i++)insert(read(),read());
    for(int i=1;i<=n;i++)if(deg[i]>2){puts("-1");return 0;}
    for(int i=1;i<=n;i++)if(deg[i]==1){root=i;break;}
    dfs(root,0);int Ans=inf;
    for(int i=0;i<3;i++)id[i]=i;
    do{
        int ret=0;
        for(int i=1;i<=n;i++)ret+=c[id[i%3]][lst[i]];
        if(ret<Ans){Ans=ret;for(int i=0;i<3;i++)ansid[i]=id[i];}
    }while(next_permutation(id,id+3));
    write(Ans);
    for(int i=1;i<=n;i++)ans[lst[i]]=ansid[i%3];
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]+1);puts("");
    return 0;
}
