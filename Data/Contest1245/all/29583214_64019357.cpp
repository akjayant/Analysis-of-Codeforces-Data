//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <random>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

using ll = long long;
using ld = long double;
using itn = int;
using dd = double;
mt19937 gen(41);
const ld eps = 1e-7;
const ll INF = 1e17;
const dd pi = acos(dd(-1));

#define endl '\n'

ll gcd(ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

/** SOLVE

SOLVE

**/

vector<int> p;

int dsu_get(int v) {
	return (v == p[v]) ? v : (p[v] = dsu_get(p[v]));
}

void dsu_unite(int a, int b) {
	a = dsu_get(a);
	b = dsu_get(b);
	if (rand() & 1)
		swap(a, b);
	if (a != b)
		p[a] = b;
}
ll n;
ll d[2001][2001];
ll x[2000], y[2000], c[2000], k[2000];

int main() {
#ifdef _DEBUG
	auto input = freopen("input.txt", "r", stdin);
	auto output = freopen("output.txt", "w", stdout);
#else
	//freopen("bst.in", "r", stdin);
	//freopen("bst.out", "w", stdout);
#endif // DEBUG
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(20);
	//--------------------------------------//
	cin >> n;
	p.resize(n + 1);
	vector < pair < ll, pair<ll, ll> > > g; // вес - вершина 1 - вершина 2
	for (ll i = 0; i < n + 1; i++) {
		p[i] = i;
	}
	for (ll i = 0; i < n; i++) {
		cin >> x[i];
		cin >> y[i];
	}
	for (ll i = 0; i < n; i++) 
		cin >> c[i];
	for (ll i = 0; i < n; i++)
		cin >> k[i];
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++) {
			d[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
			g.push_back({ d[i][j], {i, j} });
		}
	for (ll i = 0; i < n; i++) {
		g.push_back({ c[i], {i, n} });
	}
	ll m = g.size();
	ll cost = 0;
	vector <ll> res;
	sort(g.begin(), g.end());
	for (ll i = 0; i < n; ++i)
		p[i] = i;
	vector<pair<ll, ll>> edges;
	for (ll i = 0; i < m; ++i) {
		ll a = g[i].second.first, b = g[i].second.second, l = g[i].first;
		if (dsu_get(a) != dsu_get(b)) {
			cost += l;
			if (a == n) {
				res.push_back(b);
			}
			if (b == n) {
				res.push_back(a);
			}
			else {
				edges.push_back(g[i].second);
			}
			dsu_unite(a, b);
		}
	}
	cout << cost << endl;
	cout << res.size() << endl;
	for (auto i : res)
		cout << i + 1 << " ";
	cout << endl;
	cout << edges.size() << endl;
	for (auto i : edges)
		cout << i.first + 1 << " " << i.second + 1 << endl;
	//-----------------------------------------------//
	return 0;
}