#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define X first
#define Y second
#define sz(v) (int)v.size()

void solve();

main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ONPC
	freopen("in.txt", "r", stdin);
#endif
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

const int N = 1e5 + 5;
int n, m, p[N], szz[N];
ll ans, sz, sm;
vector<int> g[N];
set<int> Q;
bool used[N];

int get(int v) {
	return p[v] == v ? v : p[v] = get(p[v]);
}

void mergee(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b) return;
	if (szz[a] < szz[b]) swap(a, b);
	szz[a] += szz[b];
	p[b] = a;
}

void dfs(int v) {
	used[v] = 1;
	map<int, int> sp;
	for (auto d : g[v]) {
		sp[get(d)]++;
	}
	vector<int> del = {get(v)};
	for (auto d : Q) {
		if (get(v) != d && sp[d] != szz[d]) {
			--ans;
			del.pb(d);
		}
	}
//	cout << v << '\n';
//	if (v == 3) {
//		cout << get(2) << '\n' << get(1) << '\n' << sp[get(1)] << '\n' << szz[get(1)] << '\n';
//	}
	while (sz(del) > 1) {
//		cout << del.back() << ' ' << szz[del.back()] << '\n';
		int a = get(del[0]), b = del.back();
		mergee(del[0], del.back());
		int c = get(a);
		if (c == a) Q.erase(b);
		else Q.erase(a);
		del.pop_back();
	}
//	cout << '\n';
	for (auto d : g[v]) {
		if (!used[d]) dfs(d);
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	ans = n - 1;
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		szz[i] = 1;
		Q.insert(i);
	}
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			dfs(i);		
		}
	}
	cout << ans;
}