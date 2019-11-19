//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math") 
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,tune=native") 
// #pragma GCC target("avx,avx2")

#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>

#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double
#define ll long long

using namespace std;

const ld eps = 1e-9;
const ll inf = 1e18;
const ld PI = 3.14159265358979323846264;
const ld leng = 1e10;
const ld bigConstant = 1e6;
const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll maxv = 360;
const ll bsz = 500;
const ll maxlog = 32;


ll c[3][maxn];
vector<vector<int>> g;
ll ans[3][maxn];
ll preitog[maxn];

//
//void dfs(int v, int p = -1) {
//	if (g[v].size() == 1 && g[v][0] == p) {
//		for (int i = 0; i < 3; i++) {
//			ans[i][v] = c[i][v];
//			sum[i][v] = inf;
//		}
//		return;
//	}
//
//	for (auto u : g[v]) {
//		if (u == p) continue;
//		dfs(u);
//	}
//
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			if (i == j) continue;
//			int q = 3 - i - j;
//			ll curans = 
//		}
//	}
//}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n;
	cin >> n;
	g.resize(n);


	for (int j = 0; j < 3; j++)
		fill(ans[j], ans[j] + maxn, inf);

	for (int j = 0; j < 3; j++)
		for (int i = 0; i < n; i++)
			cin >> c[j][i];
	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	for (int i = 0; i< n; i++)
		if (g[i].size() >= 3) {
			cout << -1;
			return 0;
		}

	vector<int> ob;

	for (int i = 0; i < n; i++) {
		if (g[i].size() == 1) {
			ob.pb(i);
			break;
		}
	}
	ob.pb(g[ob.back()][0]);
	while (g[ob.back()].size() > 1) {
		int v = ob.back();
		int u = ob[ob.size() - 2];
		if (g[v][0] == u)
			ob.pb(g[v][1]);
		else
			ob.pb(g[v][0]);
	}

	ll res = inf;
	pair<int, int> best;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			ll ans = 0;
			ans += c[i][ob[0]];
			ans += c[j][ob[1]];
			int c1 = i;
			int c2 = j;
			for (int k = 2; k < n; k++) {
				int curc = 3 - c1 - c2;
				ans += c[curc][ob[k]];
				c1 = c2;
				c2 = curc;
			}
			if (ans < res) {
				res = ans;
				best = { i, j };
			}
		}
	}
	preitog[ob[0]] = best.ff;
	preitog[ob[1]] = best.ss;
	int c1 = best.ff;
	int c2 = best.ss;
	for (int k = 2; k < n; k++) {
		int curc = 3 - c1 - c2;
		preitog[ob[k]] = curc;
		c1 = c2;
		c2 = curc;
	}
	
	cout << res << endl;
	for (int i = 0; i < n; i++)
		cout << preitog[i] + 1 << ' ';

	return 0;
}