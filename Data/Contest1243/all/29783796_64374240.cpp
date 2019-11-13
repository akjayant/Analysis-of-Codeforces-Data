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
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.rbegin(), a.rend());
		int ch = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] >= i + 1) ch++;
			else break;
		}
		cout << ch << endl;
	}
}