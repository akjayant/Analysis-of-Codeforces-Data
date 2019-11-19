#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#define int long long
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
ll n, x = -1;
bool f = true;
void gao() {
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			x = i;
			f = false;
			break;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	gao();
	if (f) { cout << n; return 0; }
	if (x != -1) {
		for (; n > 1;) {
			if (n % x) break;
			n /= x;
		}
	}
	if (n != 1) cout << 1;
	else cout << x;
}