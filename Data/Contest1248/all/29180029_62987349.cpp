// Competitive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<ll> sticks(n);
	for (auto &i : sticks) cin >> i;
	sort(sticks.begin(), sticks.end());
	ll ver = 0, hor = 0;
	for (int i = 0; i < n / 2; i++) {
		ver += sticks[i];
	}
	for (int i = n / 2; i < n; i++) {
		hor += sticks[i];
	}
	cout << ver * ver + hor * hor << endl;
	return 0;
}