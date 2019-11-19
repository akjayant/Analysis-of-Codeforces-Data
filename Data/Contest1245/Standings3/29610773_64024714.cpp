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

struct dset {
	vector<int> P, R;
	dset(const int N) : P(N), R(N, 1) { iota(begin(P), end(P), 0); };
	int root(const int i) {
		return P[i]!=i ? P[i]=root(P[i]) : i;
	}
	int merge(int i, int j) {
		i=root(i), j=root(j);
		if(i==j) return 0;
		if(R[i]<R[j]) swap(i, j);
		P[j]=i;
		return R[i]+=R[j];
	}
};
struct edge {
	int i, j; ll x;
	bool operator<(const edge& b) const {
		return x<b.x;
	}
};
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int N, M; ll s=0;
	cin>>N;
	vector<int> A(N), B(N), C(N), D(N);
	vector<edge> E(N*N), F(N-1); F.clear();
	vector<vector<int>> G(N);
	rep(i, 0, N) cin>>A[i]>>B[i];
	rep(i, 0, N) cin>>C[i];
	rep(i, 0, N) cin>>D[i];

	dset ds(N);
	rep(i, 0, N) rep(j, 0, N) {
		E[i*N+j]={i, j, (abs(A[i]-A[j])+abs(B[i]-B[j]))*ll(D[i]+D[j])};
	}
	sort(begin(E), end(E));

	for(auto[i,j,x]:E) if(ds.root(i)!=ds.root(j)) {
		ds.merge(i, j);
		F.push_back({i, j, x});
		G[i].push_back(j);
		G[j].push_back(i);
		s+=x;
	}

	int min_first=min_element(begin(C), end(C))-begin(C);
	s+=C[min_first];
	C[min_first]=0;

	M=N-1;
	sort(rbegin(F), rend(F));
	for(auto&[u,v,x]:F) {
		function<int(int, int)> f=[&](int i, int p) {
			int k=i;
			for(int j:G[i]) if(j!=i && j!=p) {
				int l=f(j, i);
				if(C[l]<C[k]) k=l;
			}
			return k;
		};
		for(int&j:G[u]) if(j==v) j=u;
		for(int&j:G[v]) if(j==u) j=v;
		int a=f(u, u), b=f(v, v);
		int c=C[a]>C[b]?a:b;
		if(C[c]<=x) {
			s+=C[c]-x;
			C[c]=0;
			u=v=x=-1;
			M--;
		} else {
			for(int&j:G[u]) if(j==u) j=v;
			for(int&j:G[v]) if(j==v) j=u;
		}
	}

	cout<<s<<'\n';
	cout<<N-M<<'\n';
	rep(i, 0, N) if(!C[i]) cout<<i+1<<' ';
	cout<<'\n';
	cout<<M<<'\n';
	for(auto[u,v,x]:F) if(~u && ~v && ~x) {
		cout<<u+1<<' '<<v+1<<'\n';
	}
}