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
const ll mod = (ll)1e9 + 7;

ll t;

void solve() {
	ll n, m;
	cin >> n >> m;
	if (n > m) swap(n , m);
	ll a = 1, b = 1;
	for (int i = 0; i < n; i++) {
		a += b;
		swap(a, b);
		a %= mod;
		b %= mod;
	}
	a -= 1;
	ll d = 1, e = 1;
	for (int i = 0; i < m; i++) {
		d += e;
		swap(d, e);
		d %= mod;
		e %= mod;
	}
	cout << (a + d) * 2 % mod;
	return;
}

int main() {
	solve();
	return 0;
}
/*

baaabbaaab
bab
*/