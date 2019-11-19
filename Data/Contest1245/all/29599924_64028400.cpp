#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cctype>
#define maxn 2007
#define int long long
using namespace std;
int ans,js,head[maxn],num,x[maxn],y[maxn],k[maxn],c[maxn],fa[maxn],cnt,n,m;
struct TT {
  int u,v,w;
  bool operator < (const TT &a) const {
    return w<a.w;
  }
}a[maxn*maxn];
struct node {
  int v,nxt;
}e[maxn<<1];
int qread() {
  char c=getchar();int num=0,f=1;
  for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
  for(;isdigit(c);c=getchar()) num=num*10+c-'0';
  return num*f;
}
inline void ct(int u, int v) {
  e[++num]=(node){v,head[u]};
  head[u]=num;
}
int find(int x) {
  return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int u, int f) {
  for(int i=head[u];i;i=e[i].nxt) {
    int v=e[i].v;
    if(v==f) continue;
    printf("%lld %lld\n",u,v);
    dfs(v,u);
  }
}
void uni(int x, int y) {
  x=find(x),y=find(y);
  fa[y]=x;
}
signed main() {
  n=qread();
  for(int i=1;i<=n+1;++i) fa[i]=i;
  for(int i=1;i<=n;++i) x[i]=qread(),y[i]=qread();
  for(int i=1;i<=n;++i) c[i]=qread();
  for(int i=1;i<=n;++i) k[i]=qread();
  for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
      a[++cnt]=(TT){i,j,1ll*(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j])};
  for(int i=1;i<=n;++i) a[++cnt]=(TT){i,1+n,c[i]};
  sort(a+1,a+1+cnt);
  for(int i=1;i<=cnt;++i) {
    int u=a[i].u,v=a[i].v;
    u=find(u),v=find(v);
    if(u^v) {
      uni(u,v);
      ans+=a[i].w;
      ct(a[i].u,a[i].v),ct(a[i].v,a[i].u);
    }
  }
  printf("%lld\n",ans);
  for(int i=head[n+1];i;i=e[i].nxt) ++js;
  printf("%lld\n",js);
  for(int i=head[n+1];i;i=e[i].nxt) printf("%lld ",e[i].v);
  puts("");
  printf("%lld\n",n-js);
  for(int i=head[n+1];i;i=e[i].nxt) dfs(e[i].v,n+1);
  return 0;
}