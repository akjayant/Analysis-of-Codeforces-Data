#include <bits/stdc++.h>
#define f first
#define s second
#define push push_back
#define pop pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
// #define Bubibu
// #pragma GCC optimize("O3")
 
using namespace std;
 
typedef long long ll;
 
const ll MAXN = 1e5 + 1, INF = 1e18;
 
// mt19937 rnd(0);

int st;
vector <int> g[MAXN], stek;
ll c[MAXN][4];

ll dfs(int v, int a, int b, int d, int p) {
	ll q = (d == 0? c[v][a] : d == 1? c[v][b]: c[v][6 - a - b]);
	stek[v - 1] = (d == 0? a : d == 1? b: 6 - a - b);
	for (int i : g[v]) {
		if (i == p) {
			continue;
		}
		return dfs(i, a, b, (d + 1) % 3, v) + q; 
	}
	return q;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef Bubibu	
	freopen("out.txt", "w", stdout); 
	freopen("in.txt", "r", stdin);
	#endif
	ll n;
	cin >> n;
	stek.resize(n);
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> c[j][i];
		}
	}
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push(b);
		g[b].push(a);
		if (g[a].size() > 2 || g[b].size() > 2) {
			return cout << -1, 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (g[i].size() == 1) {
			st = i;
		}
	}
	ll ans = INF;
	vector <int> col(n);
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			if (i == j) {
				continue;
			}
			stek.assign(n, 0);
			ll tmp = dfs(st, i, j, 0, -1);
			if (ans > tmp) {
				ans = tmp;
				col = stek;
			}
		}
	}
	cout << ans << '\n';
	for (int i : col) {
		cout << i << ' ';
	}
	return 0;
}