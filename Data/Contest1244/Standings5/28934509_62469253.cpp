#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>

// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize ("-ffloat-store")

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

const ll cst = 2e5 + 5;
const ll inf = (ll)1e18 + 228;

ll t;

void solve() {
	ll n;
	string s;
	cin >> n >> s;
	ll ans = n;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '0') continue;
		ll a = 2 * max(i + 1, n - i);
		ans = max(a, ans);
	}
	//cerr << "keek ";
	cout << ans << endl;
}

int main() {
	cin >> t;
	while (t--)
		solve();
	//system("pause");
	return 0;
}

