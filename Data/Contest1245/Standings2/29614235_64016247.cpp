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

const ll MOD = 1e9 + 7;
const ll N = 1e5 + 7;

struct Ed {
	int a, b;
	ll cost;
	Ed() {};
	Ed(int a_, int b_, ll cost_) {
		a = a_;
		b = b_;
		cost = cost_;
	}
	bool operator<(Ed a) {
		return cost < a.cost;
	}
};

int n;
vector<Ed> g;
vector<pair<ll, ll>> a;
vector<ll> c, k;
vector<ll> rnk, par;

ll gett(int i1, int i2) {
	ll dist = abs(a[i1].first - a[i2].first) + abs(a[i1].second - a[i2].second);
	return dist * (k[i1] + k[i2]);
}

int fp(int v) {
	if (v == par[v]) return v;
	return par[v] = fp(par[v]);
}

bool un(int a, int b, ll cst) {
	a = fp(a);
	b = fp(b);
	if (a == b) return false;
	if (rnk[a] < rnk[b]) swap(a, b);
	if (rnk[a] == rnk[b]) rnk[a]++;
	par[b] = a;
	return true;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("linkcut.in", "r", stdin);
	//freopen("linkcut.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#endif
	cin >> n;
	//g.resize(n + 1);
	rnk.resize(n + 1);
	par.resize(n + 1);
	for (int i = 0; i < n + 1; i++) par[i] = i;
	a.resize(n + 1);
	c.resize(n + 1);
	k.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll cst = gett(i, j);
			g.pb(Ed(i, j, cst));
		}
	}
	for (int i = 0; i < n; i++) {
		g.pb(Ed(i, n, c[i]));
	}
	sort(all(g));
	ll ans = 0;
	vector<int> sc;
	vector<pair<int, int>> pe;
	for (int i = 0; i < g.size(); i++) {
		if (un(g[i].a, g[i].b, g[i].cost)) {
			ans += g[i].cost;
			if (g[i].a > g[i].b) swap(g[i].a, g[i].b);
			if (g[i].b == n) {
				sc.pb(g[i].a + 1);
			}
			else {
				pe.pb(mp(g[i].a + 1, g[i].b + 1));
			}
		}
	}
	cout << ans << nn;
	cout << sc.size() << nn;
	for (int i = 0; i < sc.size(); i++) {
		cout << sc[i] << pp;
	}
	cout << nn;
	cout << pe.size() << nn;
	for (int i = 0; i < pe.size(); i++) {
		cout << pe[i] << nn;
	}
}