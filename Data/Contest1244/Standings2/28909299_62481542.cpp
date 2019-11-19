#pragma GCC target("avx2")
#pragma GCC optimize("O3")

# include <x86intrin.h>
# include <bits/stdc++.h>

# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
 
template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _USE_MATH_DEFINES_
#define ll long long
#define ld long double
#define Accepted 0
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define every(x) x.begin(),x.end()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define For(i,x,y)  for (ll i = x; i <= y; i ++) 
#define FOr(i,x,y)  for (ll i = x; i >= y; i --)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// ROAD to...                                                                                                                                                                                                                Red

inline void Input_Output () {
	//freopen(".in", "r", stdin);
   //freopen(".out", "w", stdout);
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
 
int n, m, k;
int a[N];
vector < int > g[N];
int p[5];
int c[5][N];
int col[5];

int d[N];
void dfs (int v, int pr = 0) {
	for (auto to : g[v]) if (to != pr) {
		d[to] = d[v] + 1;
		dfs(to, v);
	}
}

int main () {
   SpeedForce;
	cin >> n;
	m = 3;
	for (int i = 0; i < m; i ++) {
		for (int j = 1; j <= n; j ++) {
			cin >> c[i][j];
		}
		p[i] = i;
	}
	for (int i = 1, x, y; i < n; i ++) {
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}

	for (int i = 1; i <= n; i ++) if (g[i].size() > 2) {
		cout << -1;
		exit(0);
	}
	int root = -1;
	for (int i = 1; i <= n; i ++) if (g[i].size() == 1) root = i;
	dfs(root);

	ll ans = INF;
	do {
		ll res = 0;
		for (int i = 1; i <= n; i ++) {
			res += c[p[d[i] % m]][i];
		}
		if (ans > res) {
			ans = res;
			for (int i = 0; i < m; i ++)
				col[i] = p[i];
		}
	} while(next_permutation(p, p + m));

	cout << ans << '\n';
	for (int i = 1; i <= n; i ++)
		cout << col[d[i] % 3] + 1 << ' ';

   return Accepted;
}

// B...a