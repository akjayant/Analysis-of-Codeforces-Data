// IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9, MOD = INF + 7;

/////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5;

int col[4][N], ans[N], per[4];
vector<int> g[N], path;

void dfs(int v = 1, int p = 0) {
	path.push_back(v);
	for(int u : g[v]) if (u != p) dfs(u, v);
	return;
}

int main() {

	sync;
	
	int n; cin >> n;
	for(int c = 1; c <= 3; c++) for(int i = 1; i <= n; i++) cin >> col[c][i];
	for(int i = 0; i < n - 1; i++) {
		int v, u; cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for(int i = 1; i <= n; i++) if (sz(g[i]) >= 3) die(-1);
	for(int i = 1; i <= n; i++) if (sz(g[i]) == 1) { dfs(i); break; }
	for(int i = 0; i < n; i++) ans[path[i]] = i % 3 + 1;
	for(int i = 1; i <= 3; i++) per[i] = i;
	ll res = INF * N;
	do {
		ll tmp = 0;
		for(int i = 1; i <= n; i++) tmp += col[per[ans[i]]][i];
		res = min(res, tmp);
	} while(next_permutation(per + 1, per + 3 + 1));
	for(int i = 1; i <= 3; i++) per[i] = i;
	cout << res << endl;
	do {
		ll tmp = 0;
		for(int i = 1; i <= n; i++) tmp += col[per[ans[i]]][i];
		if(tmp != res) continue;
		for(int i = 1; i <= n; i++) cout << per[ans[i]] << ends;
		cout << endl;
		return 0;
	} while(next_permutation(per + 1, per + 3 + 1));	

  	return 0;
}
