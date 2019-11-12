#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define push_back pb
#define make_pair mp
#define MULTITEST int _test_no; cin >> _test_no; while (_test_no-- > 0)
#define MULTITEST_SCANF int _test_no; scanf("%d", &_test_no); while (_test_no-- > 0)
#define first ff
#define second ss
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector> 
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

ll mod = 1e9 + 7;

ll binpow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		n >>= 1;
	}
	return res;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	ll ans = binpow(2, m) - 1;
	ans += mod;
	ans %= mod;
	ans = binpow(ans, n);
	cout << ans << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#elif ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//MULTITEST_SCANF
	//MULTITEST
	solve();

	return 0;
}