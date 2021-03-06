#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long ll;
typedef pair<ll, ll> pll;

long double DP[100];
long double MAP[100];

pll conv(ll code) {
	ll y0 = (code / 20) * 20;
	ll left = y0 % 20;
	if (left < 10)return pll(left, y0);
	else return pll(19 - left, y0 + 1);
}

ll conv(ll x, ll y) {
	if (y % 2 == 0)return 10 * y + (x % 10);
	else return 10 * y + 9 - (x % 10);
}

int main() {
	for (ll y = 9; y >= 0; y--) {
		for (ll x = 0; x <= 9; x++) {
			ll c;
			cin >> c;
			if (c == 0)MAP[conv(x, y)] = -1;   //梯子なし
			else MAP[conv(x, y)] = conv(x, y + c);   //梯子蟻
		}
	}
	DP[99] = 0;
	for (ll code = 98; code >= 93;code--) {
		long double d = 1;
		for (ll cn = code + 1; cn <= 99; cn++) {
			d += DP[cn] / 6;
		}
		long double ld = (long double)(code - 93) / 6;
		DP[code] = d / (1 - ld);
	}
	for (ll code = 92; code >= 0; code--) {
		DP[code] = 0;
		for (ll num = 1; num <= 6; num++) {
			ll next = code + num;
			if (MAP[next] == -1)DP[code] += DP[next] / 6;
			else {
				ll lad = MAP[next];
				if (DP[lad] > DP[next])DP[code] += DP[next] / 6;
				else DP[code] += DP[lad] / 6;
			}
		}
		DP[code] += 1;
	}
	cout << setprecision(12) << DP[0] << endl;
	return 0;
}
