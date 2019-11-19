#pragma comment(linker, "/STACK:134217728")
#pragma GCC optimize("fast-maths")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <climits>
#include <ctime>
#include <random>
using namespace std;

#define forx(_name,_from, to, value) for (int name = from; name < to; name += value)
#define rforx(_name, from, to, value) for (int name = from; name > to; name -= _value)
#define all(_STL_NAME) _STL_NAME.begin(), _STL_NAME.end()
#define rall(_STL_NAME) _STL_NAME.rbegin(), _STL_NAME.rend()
#define mp(_FIRST,_SECOND) make_pair(_FIRST,_SECOND)

typedef long long ll;
typedef unsigned long long llu;
typedef long double ld;
const ld eps = 1e-12;
mt19937 rndm;

void start() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20); cout.setf(ios::fixed);
	string FILENAME = "navalny";
	rndm.seed(time(0));
#ifdef _DEBUG
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#else
	//freopen((FILENAME + ".in").c_str(), "rt", stdin);
	//freopen((FILENAME + ".out").c_str(), "wt", stdout);
#endif
}

inline int FastIn(FILE* streamin = stdin) {
	char c = ' ';
	bool mns = false;
	int a = 0;
	while (!isdigit(c)) {
		mns = c == '-';
		c = _getc_nolock(streamin);
	}
	while (isdigit(c)) {
		a *= 10;
		a += c - '0';
		c = _getc_nolock(streamin);
	}
	return (mns ? -a : a);
}

inline void FastOut(int val, FILE* streamout = stdout) {
	if (val < 0) {
		val = -val;
		_putc_nolock('-', streamout);
	}
	bool fst = true;
	const int degree = 1000000000;
	for (int i = degree; i > 0; i /= 10) {
		int dl = val / i;
		if (dl || !fst) {
			_putc_nolock('0' + dl, streamout);
			fst = false;
		}
		val %= i;
	}
	if (fst)
		_putc_nolock('0', streamout);
	_putc_nolock('\n', streamout);
}

struct edge {
	int u, v;
	ll cost;
};

bool operator< (edge n, edge m) {
	if (n.cost != m.cost)
		return n.cost < m.cost;
	if (n.u != m.u)
		return n.u < m.u;
	return n.v < m.v;
}

const int maxn = 2005;
ll cost[maxn];
ll k[maxn];
int par[maxn];
int rnk[maxn];

ll savcost[maxn];
int find_par(int v) {
	if (par[v] == v)
		return v;
	return par[v] = find_par(par[v]);
}

ll cans = 0;

int backup_rnk[maxn];
int backup_par[maxn];
ll backup_cost[maxn];

void backup(int u) {
	cost[u] = backup_cost[u];
	rnk[u] = backup_rnk[u];
	par[u] = backup_par[u];
}

bool union_sets(int u, int v) {
	backup_cost[u] = cost[u];
	backup_cost[v] = cost[v];
	backup_par[u] = par[u];
	backup_par[v] = par[v];
	backup_rnk[u] = rnk[u];
	backup_rnk[v] = rnk[v];
	u = find_par(u);
	v = find_par(v);
	if (u == v)
		return false;
	if (rnk[u] < rnk[v])
		swap(u, v);
	if (rnk[u] == rnk[v])
		++rnk[u];
	par[v] = u;
	ll cst = min(savcost[cost[u]], savcost[cost[v]]);
	cans -= max(savcost[cost[u]], savcost[cost[v]]);
	if (cst != savcost[cost[u]])
		cost[u] = cost[v];
	cost[v] = -1;
	return true;
}

int main() {
	start();
	int n;
	cin >> n;
	vector<pair<ll, ll>> qp;
	for (int i = 0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;
		qp.emplace_back(mp(x, y));
	}
	for (int i = 0; i < n; ++i) {
		cin >> savcost[i];
		cans += savcost[i];
		cost[i] = i;
		par[i] = i;
		rnk[i] = 0;
	}
	for (int i = 0; i < n; ++i)
		cin >> k[i];


	vector<edge> edges;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			edge nv;
			nv.cost = (abs(qp[i].first - qp[j].first) + abs(qp[i].second - qp[j].second)) * (k[i] + k[j]);
			nv.u = i;
			nv.v = j;
			edges.emplace_back(nv);
		}
	}
	sort(all(edges));
	vector<edge> sav_e;
	ll ans = cans;
	int pos = 0;
	for (int i = 0; i < edges.size(); ++i) {
		if (union_sets(edges[i].u, edges[i].v)) {
			cans += edges[i].cost;
			sav_e.emplace_back(edges[i]);
			if (cans < ans)
				ans = cans, pos = sav_e.size();
			else {
				backup(edges[i].u);
				backup(edges[i].v);
				cans = ans;
				sav_e.pop_back();
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cost[i] = i;
		par[i] = i;
		rnk[i] = 0;
	}
	for (int i = 0; i < pos; ++i)
		union_sets(sav_e[i].u, sav_e[i].v);


	cout << ans << '\n';
	set<int> el;
	for (int i = 0; i < n; ++i)
		if (cost[i] != -1)
			el.insert(cost[i] + 1);
	cout << el.size() << '\n';
	for (auto i : el)
		cout << i << ' ';
	cout << '\n' << pos << '\n';
	for (int i = 0; i < pos; ++i)
		cout << sav_e[i].u + 1 << ' ' << sav_e[i].v + 1 << '\n';
	return 0;
}