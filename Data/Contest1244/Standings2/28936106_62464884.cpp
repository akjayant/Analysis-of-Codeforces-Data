#include <iostream>
#include <queue>
#include <algorithm>
#include <random>
#include <vector>
#include <assert.h>
#include <set>
#include <unordered_set>
#include <numeric>
#include <map>
#include <string>
#include <cstdlib>
#include <cstdio>

#pragma warning(disable : 4996)
using namespace std;

#define ft first
#define sd second
#define all(__array) (__array).begin(), (__array).end()
#define nl '\n'

typedef long long ll;
typedef double dl;

const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const dl EPS = 1e-8;
const dl PI = acos(-1);
random_device rnd;

const int N = (int)2e5 + 10;
const int M = 17;
const int K = 320;

const int MOD = (int)1e9 + 7;

inline void solve() {
	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	int ansP = (a + c - 1) / c;
	int ansK = (b + d - 1) / d;
	if (ansP + ansK > k) {
		cout << -1 << nl;
	}
	else {
		cout << ansP << " " << ansK << nl;
	}
}

inline void IO() {
#ifdef _SEVA
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}


int main() {
	IO();

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve();
	return 0;
}
