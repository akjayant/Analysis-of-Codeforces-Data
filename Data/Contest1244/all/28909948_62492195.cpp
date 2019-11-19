#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
using namespace std;

#define F first
#define S second
#define pb push_back
#define pii pair <int, int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define reunique(x) (x).resize(std::unique(all(x)) - (x).begin())
#define roflan ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ld long double
#define int long long

int vis[100500];
int dp[100500][3][3];
vector <int> g[100500];
vector <vector <int>> c;
int Rec(int v, int pref, int col, int par) {
	if (dp[v][pref][col] != -1)
		return dp[v][pref][col];
	int ret = 0;
	int color = c[v][col];
	int to = -1;
	if (pref == 0 && col == 1)
		to = 2;
	if (pref == 1 && col == 2)
		to = 0;
	if (pref == 0 && col == 2)
		to = 1;
	if (pref == 1 && col == 0)
		to = 2;
	if (pref == 2 && col == 1)
		to = 0;
	if (pref == 2 && col == 0)
		to = 1;
	for (auto u : g[v]) {
		if (u == par) continue;
		ret += Rec(u, col, to, v);
	}
	ret += color;
	cout << ret << '\n';
	return dp[v][pref][col] = ret;
}
void Solve() {
	for (int x = 0; x < 100500; x++) {
		for (int y = 0; y < 3; y++) {
			for (int z = 0; z < 3; z++) {
				dp[x][y][z] = -1;
			}
		}
	}
	int n;
	cin >> n;
	c.resize(n, vector <int> (3));
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < n; i++) {
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].pb(u);
		g[u].pb(v);
	}
	int sum = min({ Rec(0, -1, 0, -1), Rec(0, -1, 1, -1), Rec(0, -1, 2, -1) });
	cout << sum << '\n';

}
int kek = 228;
int dfs(int v, int pref, int col, int par) {
	int to = -1;
	for (auto u : g[v]) {
		if (u == par) continue;
		to = u;
	}
	if (to == -1) {
		return c[v][col];
	}
	int ret = 1e18;
	set <int> st;
	st.insert(0);
	st.insert(2);
	st.insert(1);
	st.erase(col);
	st.erase(pref);
	for (auto now : st) {
		int F = dfs(to, col, now, v);
		if (F < ret) {
			ret = F;
			kek = now;
		}
	}
	ret += c[v][col];
	return ret;
}
void Solve1() {
	int n;
	cin >> n;
	c.resize(n, vector <int>(3));
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < n; i++) {
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].pb(u);
		g[u].pb(v);
	}
	int leaf = -1;
	for (int i = 0; i < n; i++) {
		if (g[i].size() > 2) {
			cout << -1;
			return;
		}
		if (g[i].size() == 1) {
			leaf = i;
		}
	}
	assert(leaf != -1);
	int t1 = dfs(leaf, -1, 0, -1);
	int t2 = dfs(leaf, -1, 1, -1);
	int t3 = dfs(leaf, -1, 2, -1);
	int mn = min({t1, t2, t3});
	int x = -1, y = -1;
	if (mn == t1) {
		x = 0;
		t1 = dfs(leaf, -1, 0, -1);
	}
	else if (mn == t2) {
		x = 1;
		t2 = dfs(leaf, -1, 1, -1);
	}
	else {
		x = 2;
		t3 = dfs(leaf, -1, 2, -1);
	}
	assert(kek != 228);
	y = kek;
	vector <int> C(n);
	C[leaf] = x;
	C[g[leaf][0]] = y;
	int ver = -1;
	for (auto now : g[g[leaf][0]]) {
		if (now != leaf) {
			ver = now;
		}
	}
	assert(ver != -1);
	int pref = g[leaf][0];
	for (int i = 2; i < n; i++) {
		set <int> st;
		st.insert(0);
		st.insert(1);
		st.insert(2);
		st.erase(x);
		st.erase(y);
		int fuck = -1;
		for (auto now : g[ver]) {
			if (now != pref)
				fuck = now;
		}
		//assert(!(i != n - 1 && fuck != -1));
		C[ver] = *st.begin();
		st.insert(y);
		x = y;
		y = C[ver];
		pref = ver;
		ver = fuck;
	}
	cout << mn << '\n';
	for (int i = 0; i < n; i++) {
		C[i]++;
		cout << C[i] << ' ';
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	Solve1();

	return 0;
}