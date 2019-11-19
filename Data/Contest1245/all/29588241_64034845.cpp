#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#define f first
#define s second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define len(x) ((int)x.size())

typedef long long ll;
typedef long double ld;

using namespace std;

namespace IO {
#define AUTO_T template <typename T>
#define AUTO_TT template <class T1, class T2>
	AUTO_T ostream& operator << (ostream& out, vector <T>& p) {
		for (auto& el : p)
			out << el << ' ';
		return out;
	}
	AUTO_T istream& operator >> (istream& inp, vector <T>& p) {
		for (auto& el : p)
			inp >> el;
		return inp;
	}
	AUTO_T ostream& operator << (ostream& out, deque <T>& p) {
		for (auto& el : p)
			out << el << ' ';
		return out;
	}
	AUTO_T istream& operator >> (istream& inp, deque <T>& p) {
		for (auto& el : p)
			inp >> el;
		return inp;
	}
	AUTO_TT ostream& operator << (ostream& out, pair <T1, T2>& p) {
		out << p.f << ' ' << p.s << endl;
		return out;
	}
	AUTO_TT istream& operator >> (istream& inp, pair <T1, T2>& p) {
		inp >> p.f >> p.s;
		return inp;
	}
}
using namespace IO;

ll cost = 0;
vector <ll> ans;
vector <ll> fat;
vector <int> pr;
vector <int> sz;
vector <ll> k, c;

void init(int n) {
	sz.resize(n);
	pr.resize(n);
	ans.resize(n);
	fat.resize(n);
	cost = 0;
	for (int i = 0; i < n; i++) {
		sz[i] = 1;
		fat[i] = i;
		pr[i] = i;
		ans[i] = c[i];
	}
}

int get_par(int v) {
	if (v == pr[v])
		return v;
	return pr[v] = get_par(pr[v]);
}

void unite(int u, int v) {
	u = get_par(u);
	v = get_par(v);
	if (u == v)
		return;
	if (sz[u] < sz[v])
		swap(u, v);
	sz[u] += sz[v];
	pr[v] = u;
	if (ans[u] > ans[v]) {
		ans[u] = ans[v];
		fat[u] = fat[v];
	}
}

struct edge {
	ll w;
	int u;
	int v;
};

signed main()
{
	ios::sync_with_stdio(0);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	k.resize(n);
	c.resize(n);

	vector <pair <ll, ll>> xx(n);
	for (int i = 0; i < n; i++)
		cin >> xx[i].first >> xx[i].second;
	cin >> c;
	cin >> k;

	init(n);

	vector <edge> ed;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll w = abs(xx[i].first - xx[j].first) + abs(xx[i].s - xx[j].s);
			w = w * (k[i] + k[j]);
			ed.push_back({ w, i, j });
		}
	}

	sort(all(ed), [](const edge& A, const edge& B) {
		return A.w < B.w;
	});

	vector <pair <int, int>> res;

	for (int i = 0; i < len(ed); i++) {
		int u = get_par(ed[i].u);
		int v = get_par(ed[i].v);
		if (u == v)
			continue;
		if (max(ans[u], ans[v]) > ed[i].w) {
			cost += ed[i].w;
			unite(u, v);
			res.push_back({ ed[i].u, ed[i].v });
		}
	}

	vector <int> ver;
	for (int i = 0; i < n; i++)
		ver.push_back(get_par(i));

	sort(all(ver));
	ver.erase(unique(all(ver)), ver.end());

	for (auto el : ver)
		cost += ans[el];

	cout << cost << endl;
	cout << len(ver) << endl;
	for (auto el : ver)
		cout << fat[el] + 1 << ' ';
	cout << endl;
	cout << len(res) << endl;
	for (auto el : res)
		cout << el.first + 1 << ' ' << el.second + 1 << endl;

	return 0;
}