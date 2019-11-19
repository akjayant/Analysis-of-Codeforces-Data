#include <bits/stdc++.h>
using namespace std;
long long Read() {
	long long num=0;
	char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) {
		num=(num<<3)+(num<<1)+ch-'0';
		ch=getchar();
	}
	return num;
}
const int maxn=100005;
vector<int> G[maxn];
long long C[4][maxn],res;
long long color[maxn],ans[maxn];
void solve(int fa, int u) {
	for (int i=0; i<G[u].size(); ++i) {
		int v=G[u][i];
		if (color[v]) continue;
		for (int k=1; k<=3; ++k) {
			if (k!=color[fa]&&k!=color[u]) res+=C[k][v],color[v]=k,solve(u,v);
		}
	}
}
int main() {
	long long n=Read();
	for (int i=1; i<=3; ++i) {
		for (int j=1; j<=n; ++j) {
			C[i][j]=Read();
		}
	}
	for (int i=1; i<n; ++i) {
		int a=Read();
		int b=Read();
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int t=1;
	for (int i=1; i<=n; ++i) {
		if (G[i].size()>2) {
			cout<<-1<<endl;
			return 0;
		}
		if (G[i].size()==1) t=i;
	}
	long long minv=(1LL<<62);
	for (int i=1; i<=3; ++i) {
		for (int j=0; j<G[t].size(); ++j) {
			int v=G[t][j];
			for (int k=1; k<=3; ++k) {
				if (i==k) continue;
				memset(color,0,sizeof(color));
				color[v]=k;
				color[t]=i;
				res=C[i][t]+C[k][v];
				solve(t,v);
				if (res<minv) {
					minv=res;
					for (int i=1; i<=n; ++i) ans[i]=color[i];
				}
			}
		}
	}
	cout<<minv<<endl;
	for (int i=1; i<=n; ++i) {
		if (i!=1) cout<<" ";
		cout<<ans[i];
	}
	return 0;
}
