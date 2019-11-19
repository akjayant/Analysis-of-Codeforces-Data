/* بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ */
//codeforces1244B_live
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
ll modInverse(ll a, ll b){ return 1<a ? b - modInverse(b%a,a)*b/a : 1; }
ll gcd(ll a, ll b){ return b?gcd(b, a % b):a; }
ll lcm(ll a, ll b){ return (a*b)/gcd(a, b); }
ld dist(ll x, ll y, ll a, ll b){ return sqrt((x - a)*(x - a) + (y - b)*(y - b)); }
void debug(ll* a, ll n) { for ( int k = 0; k < n; k++ ){ cout << a[k] << " ";} cerr << "\n"; }

int main() {
	FASTIO
	ll t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		string s; cin >> s;
		ll ans = n;
		for ( ll k = 0; k < n; k++ )
			if (s[k] == '1') ans = max(ans, max(k + 2 + k, k + 1 + n - k));
		for ( ll k = n - 1; k >= 0; k--)
			if (s[k] == '1') ans = max(ans, max(2 * (n - k), n - k + 1 + n - (n - k)));
		cout << ans << "\n";
	}
	return 0;
}