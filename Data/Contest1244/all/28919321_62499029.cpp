// IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9, MOD = INF + 7;

/////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5;

int ps[N], a[N];

int32_t main() {

	sync;
	
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int ans = INF * INF;
	for(int i = 1; i <= n; i++) ps[i] = ps[i - 1] + a[i];
	for(int i = 1; i <= n; i++) {
		int cost = k - (i * a[i] - ps[i]);
		if (cost < 0) continue;
		int dw = a[i] - 1, up = a[n];
		while(up - dw > 1) {
			int md = (dw + up) / 2;
			int x = lower_bound(a + 1, a + 1 + n, md) - a;
			if (cost - (ps[n] - ps[x - 1] - md * (n - x + 1)) >= 0) up = md;
			else dw = md;
		}
		ans = min(ans, up - a[i]);
	}
	for(int i = 1; i <= n; i++) {
		int cost = k - (ps[n] - ps[i - 1] - (n - i + 1) * a[i]);
		if (cost < 0) continue;
		int dw = 0, up = a[i] + 1;
		while(up - dw > 1) {
			int md = (dw + up) / 2;
			int x = upper_bound(a + 1, a + 1 + n, md) - a - 1;
			if (cost - (x * md - ps[x]) >= 0) dw = md;
			else up = md;
		}
		ans = min(ans, a[i] - dw);
	}
	cout << ans << endl;

  	return 0;
}
