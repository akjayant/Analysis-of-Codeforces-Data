#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <bitset>
#include <set>

#define all(x) x.begin(), x.end()

#pragma GCC optmize("Ofast,unroll-loops,fast-math,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,mmx,abm,popcnt,tune=native")

using namespace std;

typedef long long ll;

const ll inf = (ll)1e18 + 228;
const ll cst = 1e5 + 5;

ll t;

void solve() {
	ll n;
	cin >> n;
	ll a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (x % 2) a++;
		else b++;
	}
	cin >> n;
	ll d = 0, e = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (x % 2) d++;
		else e++;
	}
	cerr << "ans is :";
	cout << a * d + b * e << endl;;
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}
/*

baaabbaaab
bab
*/