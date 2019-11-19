#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <assert.h>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <random>
#include <cmath>

//#define ll long long
#define ld long double
//#define mp make_pair
#define pb push_back
#define eb emplace_back
#define int long long
using namespace std;

const int INF = 2e9;
const int MOD = 1e9 + 7;
const int MB = 30;

void solve() {
	int n;
	cin >> n;
	vector<int> a;
	int d = 2;
	while (d * d <= n) {
		if (n % d == 0) {
			a.pb(d);
			if (d * d != n) a.pb(n / d);
		}
		d++;
	}

	sort(a.begin(), a.end());
	for (int i : a) {
		if (i % a[0] != 0) {
			cout << 1;
			return;
		}
	}
	cout << (a.empty() ? n : a[0]);
}

signed main() {
	/*
	freopen("cyclic.in", "r", stdin);
	freopen("cyclic.out", "w", stdout);
	*/
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(12);
	solve();
}
