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

const int N = 16;
const int M = 5005;

map < int, int > pos;
int n, cnt[N], p[1 << N];
pii start[1 << N], ans[N];
bool u[N], ok[1 << N], dp[1 << N];
ll sum, need, a[N][M], val[N], nval[N];
vector < pair < pii, int > > steps[1 << N];

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//srand(time(NULL));

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> cnt[i];
		for (int j = 1; j <= cnt[i]; j++) {
			cin >> a[i][j];
			pos[a[i][j]] = i;
			sum += a[i][j];
			val[i] += a[i][j];
		}
	}

	if (sum % n != 0) {
		cout << "No";
		return 0;
	}

	need = sum / n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= cnt[i]; j++) {
			memset(u, 0, sizeof(u));
			for (int k = 1; k <= n; k++)
				nval[k] = val[k];
			nval[i] -= a[i][j];
			bool bad = 0;
			int v = i, mask = (1 << (i - 1));
			vector < pair < pii, int > > cur_steps;
			while (1) {
				u[v] = 1;
				ll now = need - nval[v];
				if (!pos.count(now)) {
					bad = 1;
					break;
				}
				int to = pos[now];
				if (u[to]) {
					if (to != i || now != a[i][j])
						bad = 1;
					else 
						cur_steps.pb({{a[i][j], v}, to});
					break;
				}
				cur_steps.pb({{now, v}, to});
				mask |= (1 << (to - 1));
				nval[to] -= now;
				v = to;
			}
			if (bad) continue;
			/*cerr << "found " << i << " " << a[i][j] << " : ";
			for (int k = 0; k < n; k++)
				if (mask >> k & 1)
					cerr << k + 1 << " ";
			cerr << endl;*/
			ok[mask] = 1;
			start[mask] = {i, j};
			steps[mask] = cur_steps;
		}
	}

	dp[0] = 1;

	for (int mask = 1; mask < (1 << n); mask++) {
		for (int smask = mask; smask > 0; smask = ((smask - 1) & mask)) {
			if (ok[smask] && dp[mask ^ smask]) {
				dp[mask] = 1;
				p[mask] = smask;
			}
		}
	}

	if (!dp[(1 << n) - 1]) {
		cout << "No";
		return 0;
	}

	cout << "Yes" << endl;

	int mask = (1 << n) - 1;

	while (mask) {
		for (auto i : steps[p[mask]])
			ans[i.S] = i.F;
		mask ^= p[mask];
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i].F << " " << ans[i].S << endl;

	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
