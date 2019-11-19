#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a) * (a))
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)

template<class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out <<  "(" << a.x << ", " << a.y << ")";
}

template<class A> ostream& operator << (ostream& out, const vector<A> &a) {
	out << "[";
	for (auto it = a.begin(); it != a.end(); ++it) {
		if (it != a.begin())
			out << ", ";
		out << *it;
	}
	return out << "]";
}

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));

const int INF = 1e9;
const li INF64 = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9;

const int N = 100 * 1000 + 11;

int n, m;
long long k;
vector<int> xs[N], ys[N];

bool read() {
	if (scanf("%d %d %lld", &n, &m, &k) != 3)
		return false;
	forn(i, n) ys[i].clear();
	forn(i, m) xs[i].clear();
	forn(i, k) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		ys[x].pb(y);
		xs[y].pb(x);
	}
	return true;
}

li maxval(const vector<int> &vals, int l, int r, int rg) {
	if (!rg) {
		auto it = lower_bound(all(vals), l);
		if (it == vals.end()) return INF;
		return *it - l - 1;
	} else {
		auto it = upper_bound(all(vals), r);
		if (it == vals.begin()) return INF;
		--it;
		return r - *it - 1;
	}
}

void solve() {
	k = n * 1ll * m - k - 1;
	forn(i, n) sort(all(ys[i]));
	forn(i, m) sort(all(xs[i]));
	int lx = 0, rx = n - 1, ly = 0, ry = m - 1;
	int x = 0, y = 0;
	int cd = 0;
	if (m == 1 || find(all(ys[0]), 1) != ys[0].end()) cd = 1;
	while (k > 0) {
		int can = 0;
		if (cd == 0) { // right
			can = min({k, li(ry - y), maxval(ys[x], y, ry, 0)});
			y += can;
			++lx;
			ry = min(ry, y);
		} else if (cd == 1) { // down
			can = min({k, li(rx - x), maxval(xs[y], x, rx, 0)});
			x += can;
			--ry;
			rx = min(rx, x);
		} else if (cd == 2) { // left
			can = min({k, li(y - ly), maxval(ys[x], ly, y, 1)});
			y -= can;
			--rx;
			ly = max(ly, y);
		} else { // up
			can = min({k, li(x - lx), maxval(xs[y], lx, x, 1)});
			x -= can;
			++ly;
			lx = max(lx, x);
		}
		if (can <= 0) {
			puts("No");
			return;
		}
		k -= can;
		cd = (cd + 1) % 4;
	}
	puts("Yes");
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int tt = clock();
#endif

	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(10);

#ifdef _DEBUG
	while (read()) {
#else
	if (read()) {
#endif
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();	
#endif
	}
}