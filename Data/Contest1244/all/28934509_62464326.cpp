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
	ll a, b, c, d, k;
	ll ruc = 0, kar = 0;
	cin >> a >> b >> c >> d >> k;
	ruc = (a - 1) / c + 1;
	kar = (b - 1) / d + 1;
	if (ruc + kar > k) cout << -1;
	else cout << ruc << " " << kar;
	cout << endl;
}

int main() {
	cin >> t;
	while (t--)
		solve();
	//system("pause");
	return 0;
}

