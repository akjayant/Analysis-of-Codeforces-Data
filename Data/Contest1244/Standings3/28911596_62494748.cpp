/* بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ */
//codeforces1244E_live
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define mp make_pair
#define pb push_back
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
void parseArray(ll* A,ll n){ for ( ll K = 0; K < n; K++){ cin >> A[K]; } }
//ll modInverse(ll a, ll b){ return 1<a ? b - modInverse(b%a,a)*b/a : 1; }
//ll gcd(ll a, ll b){ return b?gcd(b, a % b):a; }
//ll lcm(ll a, ll b){ return (a*b)/gcd(a, b); }
ld dist(ll x, ll y, ll a, ll b){ return sqrt((x - a)*(x - a) + (y - b)*(y - b)); }
void debug(ll* a, ll n) { for ( int k = 0; k < n; k++ ){ cout << a[k] << " ";} cerr << "\n"; }

int main() {
	FASTIO
	ll n, o; cin >> n >> o;
	ll a[n]; parseArray(a, n);
	sort(a, a + n);
	ll m = a[0], ma = a[n - 1]; ll l = 0, r = n - 1;
	ll ans = 100000000000ll;
	while (1) {
		while (l < n && a[l] == m) l++;
		while (r >= 0 && a[r] == ma) r--;
		ans = min(ans, abs(ma - m));
		if (l <= n - r - 1) {
			if (o < l) break;
			ll temp = min(o / l, a[l] - m);
			m += temp;
			o -= temp * l;
		}else {
			if (o < n - r - 1) break;
			ll temp = min(o / (n - r - 1), ma - a[r]);
			ma -= temp;
			o -= temp * (n - r - 1);
		}
		ans = min(ans, abs(ma - m));
		if (l > r + 1) { ans = 0; break; }
	}
	cout << ans << endl;
	return 0;
}