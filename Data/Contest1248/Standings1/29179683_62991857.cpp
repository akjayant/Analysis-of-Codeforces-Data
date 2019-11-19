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
 
ll n, m, d[1000000][4], d_bw[1000000][4], d_wb[1000000][4];

ll qpow (ll a, ll b) {
	ll s = 1;

	while (b) {
		if (b & 1) s = s * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return s;
}

int main () {
	cin >> n >> m;

	d[0][1] = 1;
	d[0][2] = 1;

	for (int i = 1; i < max (n, m); i++) {
		d[i][0] = d[i-1][2];
		d[i][1] = (d[i-1][0] + d[i-1][2]) % MOD;
		d[i][2] = (d[i-1][1] + d[i-1][3]) % MOD;
		d[i][3] = d[i-1][1];
	}

	ll ans = d[m-1][0] + d[m-1][1] + d[m-1][2] + d[m-1][3] + MOD - 2;
	ans %= MOD;

	ans += d[n-1][0] + d[n-1][1] + d[n-1][2] + d[n-1][3];
	ans %= MOD;

	cout << ans;
}