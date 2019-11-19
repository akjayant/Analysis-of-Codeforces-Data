#include <iostream>
#include <queue>
#include <algorithm>
#include <random>
#include <vector>
#include <assert.h>
#include <set>
#include <unordered_set>
#include <numeric>
#include <map>
#include <string>
#include <cstdlib>
#include <cstdio>

#pragma warning(disable : 4996)
using namespace std;

#define ft first
#define sd second
#define all(__array) (__array).begin(), (__array).end()
#define nl '\n'

typedef long long ll;
typedef double dl;

const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const dl EPS = 1e-8;
const dl PI = acos(-1);
random_device rnd;

const int N = (int)1e5 + 10;
const int M = 17;
const int K = 320;

const int MOD = (int)1e9 + 7;

vector<int> g[N];

int costVer[3][N];
ll costAns[3][3][N];

vector<int> colors = { 0, 1, 2 };

ll dfs(int v, int p, int c) {

	ll ans = costVer[colors[c]][v];
	for (auto& to : g[v]) {
		if (p != to)
			ans += dfs(to, v, (c + 1) % 3);
	}
	return ans;
}


int anss[N];

void setColor(int v, int p, int c) {
	anss[v] = colors[c];
	for (auto& to : g[v])
		if (p != to)
			setColor(to, v, (c + 1) % 3);
}

inline void solve() {
	int n;
	cin >> n;
	for (int c = 0; c < 3; c++) {
		for (int i = 1; i <= n; i++) {
			cin >> costVer[c][i];
		}
	}

	for (int i = 0; i + 1 < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		if (g[v].size() > 2 || g[u].size() > 2) {
			cout << -1;
			return;
		}
	}

	int root = -1;
	for (int i = 1; i <= n; i++) {
		if (g[i].size() == 1) {
			root = i;
		}
	}

	ll ans = LINF;
	do {
		ll lans = dfs(root, -1, 0);
		if (lans < ans) {
			setColor(root, -1, 0);
			ans = lans;
		}
	} while (next_permutation(all(colors)));

	cout << ans << nl;
	for (int i = 1; i <= n; i++) {
		cout << anss[i] + 1 << " ";
	}
}

inline void IO() {
#ifdef _SEVA
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}


int main() {
	IO();
	solve();
	return 0;
}
