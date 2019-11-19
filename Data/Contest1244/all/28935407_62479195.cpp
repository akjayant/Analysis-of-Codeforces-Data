//#define NDEBUG
#define REL
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <string>
#include <iomanip>
#include <climits>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <stack>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <random>

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define nn "\n"
#define pp " "

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

template <typename T>
bool uax(T &a, const T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template <typename T>
bool uin(T &a, const T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
	in >> p.first >> p.second;
	return in;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> &p) {
	out << p.first << ' ' << p.second;
	return out;
}

mt19937 rnd(1928);

const int N = 1e5 + 7;

int n;
int c[N][3];
vector<vector<int>> g;
vector<int> col, pep;
ll ans = 1e18 + 7, cura = 0;
pair<int, int> check;
int cl[3];

void dfs(int v, int p, int ost) {
	pep[v] = c[v][cl[ost]];
	cura += ll(pep[v]);
	pep[v] = cl[ost] + 1;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (to == p) continue;
		dfs(to, v, (ost + 1) % 3);
	}
}


int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	g.resize(n);
	col.resize(n);
	pep.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i][0];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i][1];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i][2];
	}
	int x, y;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	x = 0, y = 0;
	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (g[i].size() == 1) { x++;  pos = i; }
		else {
			if (g[i].size() == 2) { y++; }
			else {
				cout << -1;
				exit(0);
			}
		}
	}
	if (x == 2 && y == n - x) {

	}
	else {
		cout << -1;
		exit(0);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (i != j && i != k && j != k) {
					cura = 0;
					cl[0] = i;
					cl[1] = j;
					cl[2] = k;
					dfs(pos, -1, 0);
					if (uin(ans, cura)) {
						col = pep;
					}
				}
			}
		}
	}
	cout << ans << nn;
	for (auto e : col) {
		cout << e << pp;
	}
}