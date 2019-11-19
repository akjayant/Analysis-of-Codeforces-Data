#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define pb push_back
#define X(x) { cout<<x; exit(0); }
#define rep(i,x,n) for(int i=x; i<n; i++)
#define repr(i,n,x) for(int i=n; i-->x;)
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using iii=tuple<int, int, int>;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int N, M, K=0;
	cin>>N>>M;
	set<int> A;
	vector<int> R;
	vector<bool> V(N);
	vector<vector<int>> G(N);
	rep(i, 0, N) A.insert(i);
	rep(i, 0, M) {
		int x, y;
		cin>>x>>y; --x, --y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(auto&g:G) sort(begin(g), end(g));
	function<int(int)> f=[&](int i) {
		A.erase(i), V[i]=true;
		int x=1, k=0;
		auto&g=G[i];
		for(auto it=A.begin(); it!=A.end();) {
			int j=*it;
			while(k<g.size() && g[k]<j) k++;
			if(!V[j] && (k==g.size() || g[k]!=j)) x+=f(j);
			it=A.upper_bound(j);
		}
		return x;
	};
	rep(i, 0, N) if(!V[i]) f(i), K++;
	cout<<K-1;
}