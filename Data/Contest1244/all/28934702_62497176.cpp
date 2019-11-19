#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <set>
#include <cstring>
#include <assert.h>
#include <cstdlib>
#include <cmath>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
const ll INF = 1e9, MOD = 1e9 + 7, MOD2 = 1e6 + 3;

ll a[1000000], n, p_l[1000000], p_r[1000000], ans = 1e18, k;
 
int main () {
	cin >> n >> k;

	for (ll i = 0; i < n; i++) {
		scanf ("%lld", &a[i]);
	}

	sort (a, a + n);

	for (ll i = 1; i < n; i++) {
		p_l[i] = p_l[i-1] + i * (a[i] - a[i-1]);
	}

	for (ll i = n - 2; i >= 0; i--) {
		p_r[i] = p_r[i+1] + (n - 1 - i) * (a[i + 1] - a[i]);
	}

	for (ll i = 0; i < n; i++) {
		ll left = k - p_r[i];
		if (left < 0) continue;
		ll v = upper_bound (p_l, p_l + n, left) - p_l;
		v--;

		left -= p_l[v];

		ll r = a[i];
		ll l = a[v] + left / (v + 1);

		ans = min (ans, max (0LL, r - l));
	}

	reverse (p_r, p_r + n);

	for (ll i = 0; i < n; i++) {
		ll left = k - p_l[i];
		if (left < 0) continue;
		ll v = upper_bound (p_r, p_r + n, left) - p_r;
		v--;


		left -= p_r[v];

		ll r = a[n - v - 1] - left / (v + 1);
		ll l = a[i];

		ans = min (ans, max (0LL, r - l));
	}

	cout << ans;
}