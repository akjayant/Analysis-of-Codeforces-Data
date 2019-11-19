#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#define ll long long


using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;
	vector <ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll A = 0; ll B = 0;
	for (int i = 0; i < n / 2; ++i) {
		A += a[i];
	}
	for (int i = n / 2; i < n; ++i) {
		B += a[i];
	}
	cout << A * A + B * B;
}