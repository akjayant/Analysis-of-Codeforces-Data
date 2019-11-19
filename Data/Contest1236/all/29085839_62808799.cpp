#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

typedef pair < db, db > pdd;
typedef pair < db, ld > pdl;
typedef pair < ld, db > pld;
typedef pair < ld, ld > ldp;

typedef pair < ll, ll > pll;
typedef pair < int, ll > pil;
typedef pair < ll, int > pli;
typedef pair < int, int > pii;

#define F first
#define S second

#define en end()
#define bg begin()

#define rev reverse
#define mp make_pair
#define pb push_back

#define y1 y1234567890
#define um unordered_map

#define all(x) x.bg, x.en
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)

#define sqr(x) ((x + 0ll) * (x))
#define sqrd(x) ((x + 0.0) * (x))

#define forn(i, n) for (int i = 1; i <= n; i++)

const ll inf = (ll)1e18;
const ll mod = (ll)1e9 + 7;

const db eps = (db)1e-9;
const db pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 100500;

ll ans;
int n, m, k;
set < int > :: iterator it;
set < int > row[N], col[N];

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//srand(time(NULL));

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	cin >> n >> m >> k;

	bool ex = 0;

	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		row[x].insert(y);
		col[y].insert(x);
		if (x == 1 && y == 2)
			ex = 1;
	}

	if (m == 1 || ex) {
		for (int i = 1; i <= n; i++) {
			if (col[1].find(i) != col[1].en)
				break;
			ans++;
		}
		cout << (n * 1ll * m - ans == k ? "Yes" : "No");
		return 0;
	}

	ans = 1;
	int lx(1), rx(n), ly(1), ry(m), x(1), y(1), dir = 0;

	while (1) {
		//cerr << x << " " << y << " : " << lx << " " << rx << ", " << ly << " " << ry << " :: " << ans << endl;
		if (dir == 0) {
			it = row[x].lower_bound(y);
			if (it != row[x].en && (*it) <= ry) {
				if (y == (*it) - 1)
					break;
				ans += (*it) - y - 1;
				y = ry = (*it) - 1;
			}
			else {
				if (ry == y)
					break;
				ans += ry - y;
				y = ry;
			}
			lx++;
		}
		else if (dir == 1) {
			it = col[y].lower_bound(x);
			if (it != col[y].en && (*it) <= rx) {
				if (x == (*it) - 1)
					break;
				ans += (*it) - x - 1;
				x = rx = (*it) - 1;
			}
			else {
				if (rx == x)
					break;
				ans += rx - x;
				x = rx;
			}
			ry--;
		}
		else if (dir == 2) {
			it = row[x].lower_bound(ly);
			if (it != row[x].en && (*it) <= y) { 
				int mx = -1;
				for (auto i : row[x])
					if (i <= y)
						mx = max(mx, i);
				assert(mx != -1);
				if (y == mx + 1)
					break;
				ans += y - mx - 1;
				y = ly = mx + 1;
			}
			else {
				if (ly == y)
					break;
				ans += y - ly;
				y = ly;
			}
			rx--;
		}
		else {
			it = col[y].lower_bound(lx);
			if (it != col[y].en && (*it) <= x) {
				int mx = -1;
				for (auto i : col[y])
					if (i <= x)
						mx = max(mx, i);
				assert(mx != -1);
				if (x == mx + 1)
					break;
				ans += x - mx - 1;
				x = lx = mx + 1;
			}
			else {
				if (x == lx)
					break;
				ans += x - lx;
				x = lx;
			}
			ly++;
		}
		dir = (dir + 1) % 4;
	}

	//cerr << ans << endl;

	cout << (n * 1ll * m - ans == k ? "Yes" : "No");
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
