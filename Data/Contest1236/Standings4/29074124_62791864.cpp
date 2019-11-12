#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#define M 1000000007
using namespace std;
typedef long long ll;

ll ar[1000010];

ll powr(ll a, ll p, ll m) {
	if (p == 0) {
		return 1;
	}
	if (p%2 == 0) {
		ll x = powr(a, p/2, m);
		return 	(x*x)%m;
	}
	return (a*powr(a, p-1, m) ) % m;
}

int main () {
	// freopen ("input.txt", "r", stdin);
	ll t, n, i, ans, a, b, c, max_a, max_c, max_b, m;
	// cin >> t;
	t = 1;
	while (t--) {
		cin >> n >> m;
		ans = powr(2, m, M);
		ans = (ans - 1 + M) % M;
		ans = powr(ans, n, M);
		ans = ans % M;
		cout << ans << endl;
	}
	return 0;
}