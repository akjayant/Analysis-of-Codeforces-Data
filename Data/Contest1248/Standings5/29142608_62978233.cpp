
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

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;

const int INF = 2e9;

void go() {
	int n;
	cin >> n;
	int odd1 =  0;
	int even1 = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x % 2) odd1++;
		else even1++;
	}
	int m;
	cin >> m;
	int odd2 = 0;
	int even2 = 0;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (x % 2) odd2++;
		else even2++;
	}
	cout << (odd1 * odd2 + even1 * even2) << '\n';
}

void solve() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		go();
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(12);
	/*
	freopen("distance4.in", "r", stdin);
	freopen("distance4.out", "w", stdout);
	*/
	solve();
}