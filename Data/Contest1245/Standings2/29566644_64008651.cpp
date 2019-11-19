#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxm = 4e6 + 5 + 2005;
const int maxn = 2005;

struct DSU{
	int lab[maxn];

	void Init (void){
		memset (lab, -1, sizeof lab);
	}
	int finds (int u){
		if (lab[u] < 0) return u;
		return lab[u] = finds (lab[u]);
	}
	bool same (int u, int v){
		return (finds (u) == finds (v));
	}
	void merges (int u, int v){
		u = finds (u); v = finds (v);
		if (u == v) return;
		if (lab[v] < lab[u]) swap (u, v);
		lab[u] += lab[v];
		lab[v] = u;
	}
}dsu;

struct edge_list {
	ll u, v, w;
	bool operator < (const edge_list & other) const {
		return w < other.w;
	}
};

edge_list edge[maxm];
int x[maxn], y[maxn], c[maxn], k[maxn];
int M;int N;


signed main (void){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i=1; i<=N; ++i)
		cin >> x[i] >> y[i];
	for (int i=1; i<=N; ++i)
		cin >> c[i];
	for (int i=1; i<=N; ++i)
		cin >> k[i];
	for (int i=0; i<=N; ++i){
		for (int j=i+1; j<=N; ++j){
			if (i==0){
				++M;
				edge[M] = {i, j, c[j]};
			}
			else {
				++M;
				edge[M] = {i, j, (abs(x[i]-x[j]) + abs(y[i]-y[j])) * (k[i] + k[j])};
			}
		}
	}
	vector <pair <int, int>> res2;
	vector <int> res1;
	sort (edge + 1, edge + 1 +M);
	dsu.Init ();
	ll MST = 0;
	for (int i=1; i<=M; ++i){
		int u = edge[i].u, v = edge[i].v;
		ll w = edge[i].w;
		if (!dsu.same (u, v)){
			MST += w;
			dsu.merges (u, v);
			if (u == 0) res1.pb (v);
			else res2.pb (mp (u, v));
		}
	}
	cout << MST << '\n';
	cout << res1.size() << '\n';
	for (auto it : res1) cout << it << ' ';
	cout << '\n';
	cout << res2.size() << '\n';
	for (auto it : res2) cout << it.fi << ' ' << it.se << '\n'; 
}

