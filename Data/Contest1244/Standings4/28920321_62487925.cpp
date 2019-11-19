#include <algorithm>
#include <cassert>
#include <fstream>
#include <utility>
#include <cstdio>
#include <vector>
#include <bitset>
#include <string>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second

#pragma warning(disable:4996)

using namespace std;

template<class T> inline void chkmin(T &a, T b) {
	if (a > b) a = b;
}

template<class T> inline void chkmax(T &a, T b) {
	if (a < b) a = b;
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

#include <iostream>
//const string FILENAME = "test";
//ifstream cin(FILENAME + ".in");
//ofstream cout(FILENAME + ".out");

const int MAXN = 1e5 + 7;
const ll INF = 1e18 + 9;

ll cost[MAXN][3];
ll d[MAXN][3][3];
vector<int> g[MAXN];
vector<int> path;

void EnumerateVertices(int v, int p) {
	path.push_back(v);
	for (int u : g[v]) {
		if (u == p) continue;
		EnumerateVertices(u, v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int q = 0; q < 3; ++q) {
		for (int v = 0; v < n; ++v) {
			cin >> cost[v][q];
		}
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int root = -1;
	for (int v = 0; v < n; ++v) {
		if (g[v].size() > 2) {
			cout << "-1\n";
			return 0;
		}
		if (g[v].size() == 1)
			root = v;
	}
	EnumerateVertices(root, -1);
	//for (int i = 0; i < n; ++i) {
	//}
	int v = g[root][0], p = root;
	for (int q = 0; q < 3; ++q) {
		for (int w = 0; w < 3; ++w) {
			if (q != w)
				d[1][q][w] = cost[path[0]][q] + cost[path[1]][w];
			else
				d[1][q][w] = INF;
		}
	}
	for (int i = 2; i < n; ++i) {
		for (int q = 0; q < 3; ++q) {
			for (int w = 0; w < 3; ++w) {
				if (q == w)
					d[i][q][w] = INF;
				else
					d[i][q][w] = cost[path[i]][w] + d[i - 1][3 - q - w][q];
			}
		}
	}
	ll result = INF;
	pi col = pi(-1, -1);
	for (int q = 0; q < 3; ++q) {
		for (int w = 0; w < 3; ++w) {
			if (result > d[n - 1][q][w]) {
				result = d[n - 1][q][w];
				col = pi(q, w);
			}
		}
	}
	cout << result << '\n';
	int q = col.first;
	int w = col.second;
	int ans[MAXN];
	for (int i = n - 1; i >= 0; --i) {
		ans[path[i]] = w;
		int tmp = w;
		w = q;
		q = 3 - tmp - w;
	}
	for (int v = 0; v < n; ++v) {
		cout << ans[v] + 1 << ' ';
	}
	cout << '\n';
}

