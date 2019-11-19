#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define ll long long
#define inf 0x7f7f7f7f7f7f7f7f
using std::queue;
using std::map;
using std::multiset;
using std::vector;
const int maxn=1e5+6;
template<class T>inline void read(T &x) {
   	T f=1;x=0;char s=getchar();
   	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
   	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s&15);s=getchar();}
   	x*=f;
}
template<class T>inline T min(T a,T b) { return a<b?a:b; }
template<class T>inline T max(T a,T b) { return a>b?a:b; }
template<class T>inline T fabs(T a) { return a>0?a:-a; }
struct Edge {
	int u,v;
}e[maxn<<1];
int head[maxn],ecnt;
inline void addedge(int u,int v) { e[++ecnt].v=v;e[ecnt].u=head[u];head[u]=ecnt; }
inline void add(int u,int v) { addedge(u,v); addedge(v,u); }
int n,c[3][maxn],a,b,cnt[maxn],fa[maxn],gf[maxn],root,co[maxn],idans;
vector<int> C;
ll rans,gans;
inline void dfs1(int x,int f) {
	fa[x]=f;
	for(int i=head[x];i;i=e[i].u) {
		if(e[i].v==f) continue;
		dfs1(e[i].v,x);
	}
}
inline void dfs(int x,int num) {
	int vis[3];
	int pd=0;
	for(int i=head[x];i;i=e[i].u) {
		if(e[i].v==fa[x]) continue;
		memset(vis,0,sizeof(vis));
		if(fa[x]) vis[co[fa[x]]]=1; vis[co[x]]=1;
		if(x==root) {
			C.clear();
			if(num&1) {
				for(int j=0;j<3;j++) if(!vis[j]) C.push_back(j);
			}
			else {
				for(int j=2;j>=0;j--) if(!vis[j]) C.push_back(j);
			}
			if(!pd) co[e[i].v]=C[0];
			else co[e[i].v]=C[1];
			pd=1;
		}
		else {
			for(int j=0;j<3;j++) if(!vis[j]) co[e[i].v]=j;
		}
		dfs(e[i].v,num);
	}
}
inline void getans(int num) {
	gans=0ll;
	for(int i=1;i<=n;i++) gans+=c[co[i]][i];
	if(gans<rans) idans=num;
	rans=min(rans,gans);
}
int main() {
	rans=inf;
	read(n);
	for(int i=0;i<3;i++)
	for(int j=1;j<=n;j++)
	read(c[i][j]);
	for(int i=1;i<n;i++) {
		read(a); read(b); add(a,b);
		cnt[a]++; cnt[b]++;
	}
	for(int i=1;i<=n;i++) {
		if(cnt[i]>=3) { printf("-1"); return 0; }
	}
	for(int i=1;i<=n;i++) {
		if(cnt[i]==2) { root=i; break; }
	}
	dfs1(root,0);
	co[root]=0; dfs(root,0); getans(0); dfs(root,1); getans(1);
	co[root]=1; dfs(root,2); getans(2); dfs(root,3); getans(3);
	co[root]=2; dfs(root,4); getans(4); dfs(root,5); getans(5);
	printf("%lld\n",rans);
	if(idans>=0&&idans<=1) co[root]=0;
	else if(idans==2||idans==3) co[root]=1;
	else co[root]=2;
	dfs(root,idans);
	for(int i=1;i<=n;i++) printf("%d ",co[i]+1);
}
