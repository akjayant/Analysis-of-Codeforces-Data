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

const ll M1 = 1e9 + 7;
const ll M2 = 1e9 - 7;
const ll B1 = 29;
const ll B2 = 73;
const ll INF = 4e18;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

vector <vector <int> > g;
vector <ll> color[3];
vector < vector <vector <ll>>> dp;
vector <ll> c;

void calc(int u, int p = -1) {
	dp[u][0][1] = 0;
	dp[u][0][2] = 0;

	dp[u][1][0] = 0;
	dp[u][1][2] = 0;

	dp[u][2][0] = 0;
	dp[u][2][1] = 0;
	for (auto v : g[u]) {
		if (v == p)
			continue;
		calc(v, u);
		dp[u][0][1] += dp[v][2][0];
		dp[u][0][2] += dp[v][1][0];

		dp[u][1][0] += dp[v][2][1];
		dp[u][1][2] += dp[v][0][1];

		dp[u][2][0] += dp[v][1][2];
		dp[u][2][1] += dp[v][0][2];
	}
	dp[u][0][1] += color[0][u];
	dp[u][0][2] += color[0][u];

	dp[u][1][0] += color[1][u];
	dp[u][1][2] += color[1][u];

	dp[u][2][0] += color[2][u];
	dp[u][2][1] += color[2][u];
}

void recolor(int u, int p, int clr, int clrup) {
	c[u] = clr;
	for (auto v : g[u]) {
		if (v == p)
			continue;
		int nc = 0;
		int l = clr;
		int r = clrup;
		if (l > r)
			swap(l, r);
		if (l == 0 && r == 1)
			nc = 2;
		if (l == 1 && r == 2)
			nc = 0;
		if (l == 0 && r == 2)
			nc = 1;
		recolor(v, u, nc, clr);
	}
}
 
signed main()
{
	ios::sync_with_stdio(0);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	int n;
	cin >> n;

	g.resize(n);
	c.resize(n);

	color[0].resize(n);
	color[1].resize(n);
	color[2].resize(n);

	cin >> color[0];
	cin >> color[1];
	cin >> color[2];

	dp.resize(n, vector <vector <ll>>(3, vector <ll>(3, INF)));

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int y = 0;

	for (int i = 0; i < n; i++) {
		if (len(g[i]) > 2)
			return cout << -1, 0;
		if (len(g[i]) == 1)
			y = i;
	}

	calc(y);
	ll ans = INF;
	int ct = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (ans > dp[y][i][j]) {
				c[y] = i;
				ct = j;
				ans = dp[y][i][j];
			}
		}
	}

	cout << ans << endl;
	recolor(y, -1, c[y], ct);
	for (auto el : c)
		cout << el + 1 << ' ';
	
	return 0;
}