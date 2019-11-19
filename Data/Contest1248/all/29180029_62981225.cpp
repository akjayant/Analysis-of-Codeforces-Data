// Competitive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll handle_case() {
	int n, m;
	cin >> n;
	ll pos_even = 0, pos_odd = 0, neg_even = 0, neg_odd = 0;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (abs(x) % 2 == 0) {
			pos_even++;
		}
		else {
			pos_odd++;
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (abs(x) % 2 == 0) {
			neg_even++;
		}
		else {
			neg_odd++;
		}
	}
	return pos_even * neg_even + pos_odd * neg_odd;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << handle_case() << "\n";
	}
	return 0;
}