
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



void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());

	int one = 0;
	int two = 0;
	for (int i = 0; i < n / 2 + n % 2; i++) {
		one += a[i];
	}
	for (int i = n / 2 + n % 2; i < n; i++) {
		two += a[i];
	}
	cout << one * one + two * two;
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