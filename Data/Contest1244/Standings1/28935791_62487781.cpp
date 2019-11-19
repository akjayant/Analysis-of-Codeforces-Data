#include <iostream>
#include <vector>
typedef long long ll;
constexpr int maxn=100010;
constexpr ll inf=1ll<<62;
inline void smin(ll& s,const ll& a) { if (s>a) s=a; }
int c[3][maxn],fa[maxn];
std::vector<int> G[maxn];
int col[maxn],_cc[maxn];
ll sum;
void dfs(int u,int a,int b) {
	col[u]=b+1; sum+=c[b][u];
	for (auto v:G[u]) if (v!=fa[u]) {
		fa[v]=u; dfs(v,b,3-a-b);
	}
}
int main() {
	int n; std::cin>>n;
	for (int i=1;i<=n;++i) std::cin>>c[0][i];
	for (int i=1;i<=n;++i) std::cin>>c[1][i];
	for (int i=1;i<=n;++i) std::cin>>c[2][i];
	for (int i=1;i<n;++i) {
		int u,v; std::cin>>u>>v;
		G[u].emplace_back(v),G[v].emplace_back(u);
	}
	int rt=0;
	for (int i=1;i<=n;++i) if (G[i].size()>2) {
		std::cout<<"-1\n";
		return 0;
	}
	else if (G[i].size()==1) rt=i;
	int u=G[rt].front(); fa[u]=rt;
	ll ans=inf;
	for (int i=0;i<3;++i) for (int j=0;j<3;++j) if (i!=j) {
		dfs(u,i,j);
		if (ans>sum+c[i][rt]) {
			ans=sum+c[i][rt];
			for (int i=1;i<=n;++i) _cc[i]=col[i];
			_cc[rt]=i+1;
		}
		sum=0;
	}
	std::cout<<ans<<std::endl;
	for (int i=1;i<=n;++i) std::cout<<_cc[i]<<"\n "[i!=n];
}