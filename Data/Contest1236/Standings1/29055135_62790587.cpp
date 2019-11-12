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

int n, m;

bool read() {
	if (!(cin >> n >> m))
		return false;
	return true;
}

int binpow(int a, int pw) {
	int res = 1;
	while (pw) {
		if (pw & 1) res = (res * 1ll * a) % MOD;
		a = (a * 1ll * a) % MOD;
		pw >>= 1;
	}
	return res;
}

void solve() {
	int x = (binpow(2, m) - 1 + MOD) % MOD;
	cout << binpow(x, n) << endl;
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