#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define push_back pb
#define make_pair mp
#define MULTITEST int _test_no; cin >> _test_no; while (_test_no-- > 0)
#define MULTITEST_SCANF int _test_no; scanf("%d", &_test_no); while (_test_no-- > 0)
#define first ff
#define second ss
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector> 
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

void fail() {
	cout << "No" << endl;
	exit(0);
}

class piiComparator {
public:
	bool operator() (const pii a, const pii b) const {
		return a.ff > b.ff || (a.ff == b.ff && a.ss < b.ss);
	}
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vi> xs(n);
	vector<vi> ys(m);
	vi xsizes(n);
	vi ysizes(m);

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		
		xs[x].pb(y);
		ys[y].pb(x);
	}
	for (int i = 0; i < xs.size(); i++) {
		sort(xs[i].begin(), xs[i].end());
		xsizes[i] = xs[i].size();
	}
	for (int i = 0; i < ys.size(); i++) {
		sort(ys[i].begin(), ys[i].end());
		ysizes[i] = ys[i].size();
	}

	int x = 0, y = 0;
	int dir = 0;

	int xmin = 0, xmax = n - 1;
	int ymin = 0, ymax = m - 1;
	int t = 0;
	ll total = (ll)n * (ll)m;
	total -= k;
	total--;
	while (total > 0) {
		if (dir == 0) {
			while (ymax != y && ysizes[ymax] >= n - t) {
				ymax--;
			}
			auto it = lower_bound(xs[x].begin(), xs[x].end(), y);
			if (it == xs[x].end() || *it > ymax) {
				xsizes[x] += ymax - y;
				total -= ymax - y;
				y = ymax;
			}
			else {
				fail();
			}
		}
		else if (dir == 1) {
			while (xmax != x && xsizes[xmax] >= m - t) {
				xmax--;
			}
			auto it = lower_bound(ys[y].begin(), ys[y].end(), x);
			if (it == ys[y].end() || *it > xmax) {
				ysizes[y] += xmax - x;
				total -= xmax - x;
				x = xmax;
			}
			else {
				fail();
			}
			t++;
		}
		else if (dir == 2) {
			while (ymin != y && ysizes[ymin] >= n - t) {
				ymin++;
			}
			auto it = lower_bound(xs[x].begin(), xs[x].end(), ymin);
			if (it == xs[x].end() || *it > y) {
				xsizes[x] += y - ymin;
				total -= y - ymin;
				y = ymin;
			}
			else {
				fail();
			}
		}
		else {
			while (xmin != x && xsizes[xmin] >= m - t) {
				xmin++;
			}
			auto it = lower_bound(ys[y].begin(), ys[y].end(), xmin);
			if (it == ys[y].end() || *it > x) {
				ysizes[y] += x - xmin;
				total -= x - xmin;
				x = xmin;
			}
			else {
				fail();
			}
			t++;
		}
		dir++;
		dir %= 4;
	}
	cout << "Yes" << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#elif ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//MULTITEST_SCANF
	//MULTITEST
	solve();

	return 0;
}