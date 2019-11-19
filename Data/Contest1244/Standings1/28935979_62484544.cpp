#include<bits/stdc++.h>
using namespace std;
typedef long long giant;
template<typename T> inline T& Min(T &x,const T &y) {return y<x?(x=y):x;}
template<typename T> inline T& Max(T &x,const T &y) {return x<y?(x=y):x;}
inline int read() {
	int x=0,f=1;
	char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int maxn=1e5+10;
const giant inf=1e18;
int n;
giant cost[3][maxn],b[6][maxn];
namespace tree {
	vector<int> g[maxn];
	int leaf;
	inline void add(int x,int y) {
		g[x].push_back(y);
		g[y].push_back(x);
	}
	bool impossible() {
		for (int i=1;i<=n;++i) if (g[i].size()>2) return true;
		return false;
	}
	void find() {
		for (int i=1;i<=n;++i) if (g[i].size()==1) {
			leaf=i;
			break;
		}
	}
	void work(int fa,int x,int c1,int c2,giant b[]) {
		b[x]=c2;
		for (int v:g[x]) if (v!=fa) work(x,v,c2,3-c1-c2,b);
	}
	void paint(int c1,int c2,giant b[]) {
		b[leaf]=c1;
		work(leaf,g[leaf][0],c1,c2,b);
		for (int i=1;i<=n;++i) b[0]+=cost[b[i]][i];
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif
	n=read();
	for (int i=0;i<3;++i) for (int j=1;j<=n;++j) cost[i][j]=read();
	for (int i=1;i<n;++i) {
		int x=read(),y=read();
		tree::add(x,y);
	}
	if (tree::impossible()) {
		puts("-1");
		return 0;
	}
	tree::find();
	int c=0;
	for (int i=0;i<3;++i) for (int j=0;j<3;++j) if (i!=j) {
		tree::paint(i,j,b[c++]);
	}
	giant ans=inf;
	int id=-1;
	for (int j=0;j<c;++j) if (b[j][0]<ans) ans=b[j][0],id=j;
	printf("%lld\n",ans);
	for (int i=1;i<=n;++i) printf("%lld%c",b[id][i]+1," \n"[i==n]);
	return 0;
}
