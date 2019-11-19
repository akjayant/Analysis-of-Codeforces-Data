#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 7;
int kol(int ch) {
	int c = 0;
	while (ch) {
		ch /= 10;
		c++;
	}
	return c;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	if (n == 2) {
		cout << 2;
		return 0;
	}
	if (n == 3) {
		cout << 3;
		return 0;
	}
	if (n == 4) {
		cout << 2;
		return 0;
	}
	if (n == 5) {
		cout << 5;
		return 0;
	}
	bool pr = 1;
	vector<int> d;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) d.push_back(i);
	}
	if (d.size() && d[0] * d[0] != n) {
		d.push_back(n / d[0]);
	}
	if (d.size() == 0) {
		cout << n;
		return 0;
	}

	for (int i = 1; i < d.size(); i++) {
		if (!(d[i] % d[i - 1]==0 || d[i-1]%d[i]==0)) pr = 0;
	}
	if (pr) cout << d[0];
	else cout << 1 << endl;
	
}