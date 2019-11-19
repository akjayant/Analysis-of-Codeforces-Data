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
 
int n;
ll k;
int a[N];
ll pf[N];
ll sf[N];


int main () {
   SpeedForce;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i ++) {
		pf[i] = pf[i - 1] + a[i];
	}

	for (int i = n; i >= 1; i --) {
		sf[i] = sf[i + 1] + a[i];
	}
	int ans = a[n] - a[1];
	for (int i = 1; i <= n; i ++) {
		if (a[i] * (ll)i - pf[i] > k) continue;
		ll stay = k - a[i] * (ll)i + pf[i];

		int l = a[i], r = a[n], res = a[n];
		while (l <= r) {
			int md = (l + r) >> 1;
			int pos = upper_bound(a + 1, a + n + 1, md) - a;
			//cout << "bin:" << pos << ' ' << md << '\n';

			if (sf[pos] - md * (ll)(n - pos + 1) <= stay) {
				r = md - 1;
				res = md;
			} else l = md + 1;
		}
		//cout << a[i] << ' ' << res << '\n';
		ans = min(ans, res - a[i]);
	}

	for (int i = n; i >= 1; i --) {
		if (sf[i] - a[i] * (ll)(n - i + 1) > k) continue;
		ll stay = k - (sf[i] - a[i] * (ll)(n - i + 1));
		int l = a[1], r = a[i], res = a[1];
		while (l <= r) {
			int md = (l + r) >> 1;
			int pos = upper_bound(a + 1, a + n + 1, md) - a - 1;
			//cout << "bin:" << pos << ' ' << md << '\n';

			if (md * (ll)pos - pf[pos] <= stay) {
				res = md;
				l = md + 1;
			} else r = md - 1;
		}
		//cout << a[i] << ' ' << res << '\n';
		ans = min(ans, a[i] - res);
	}
	cout << ans << '\n';

   return Accepted;
}

// B...a