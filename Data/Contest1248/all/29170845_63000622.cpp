#include <bits/stdc++.h>
#define MAX (ll)(2e5+5)
#define MOD (ll)(1e9 + 7)
#define INF (ll)(1e17 + 5)
#define PI (double)(3.14159265)

using namespace std;
using ll = long long;

ll add (ll a, ll b) {
	return (a + b) % MOD;
}

ll mult (ll a, ll b) {
	return (a * b) % MOD;
}

int main () {
	ll n, m;
	cin >> n >> m;
	ll ma = max (n, m);
	vector <ll> ve;
	ll s = 2, d = 0, v1 = 0, v2 = 0;
	ve.push_back (0);
	ve.push_back (add (s, d));
	for (ll i = 1; i < ma; i++) {
		ll ss = add (s, d);
		d = s;
		s = ss;
		ve.push_back (add (s, d));
	}
	cout << (ve[n] + ve[m] - 2) % MOD << "\n";
}
