#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>

// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize ("-ffloat-store")

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

const ll cst = 2e5 + 5;
const ll inf = (ll)1e18 + 228;

ll t;

vector<ll> g[cst];

ll c[3][cst];

ll root;

void ddfs(ll v, ll pr = -1) {
	ll cls = 0;
	for (ll u : g[v]) {
		if (u == pr) continue;
		cls++;
		ddfs(u, v);
	}
	if (cls == 0) root = v;
}

ll pat[3] = { 0, 1, 2 };

ll apat[3];

ll clr[cst];

ll dfs(ll v, ll pr = -1, ll d = 0) {
	clr[v] = pat[d] + 1;
	for (ll u : g[v]) {
		if(u == pr) continue;
		return dfs(u, v, (d + 1) % 3) + c[pat[d]][v];
	}
	return c[pat[d]][v];
}

void solve() {
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[0][i];
	for (int i = 1; i <= n; i++) cin >> c[1][i];
	for (int i = 1; i <= n; i++) cin >> c[2][i];
	for (int i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		if (g[a].size() > 2) {
			cout << -1;
			cout << endl;
			return;
		}
		if (g[b].size() > 2) {
			cout << -1;
			cout << endl;
			return;
		}
	}
	ddfs(1);
	ll ans = inf;
	do {
		ll x = dfs(root);
		if (ans > x) {
			ans = x;
			apat[0] = pat[0];
			apat[1] = pat[1];
			apat[2] = pat[2];
		}
	} while (next_permutation(pat, pat + 3));
	cout << ans << endl;
	pat[0] = apat[0];
	pat[1] = apat[1];
	pat[2] = apat[2];
	dfs(root);
	for (int i = 1; i <= n; i++) cout << clr[i] << " ";
}

int main() {
	t = 1;
	while (t--)
		solve();
	//system("pause");
	return 0;
}

