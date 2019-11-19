#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

vector<int> cnt;
int n; string s;

void form() {
	int n = s.length();
	if (n % 2 == 1) {
		cout << 0 << endl << "1 1" << endl;
		exit(0);
	}
	cnt.resize(n, 0);
	cnt[0] = s[0] == '(' ? 1 : -1;
	for (int i = 1; i < n; ++i) {
		if (s[i] == '(')
			cnt[i] = cnt[i - 1] + 1;
		else cnt[i] = cnt[i - 1] - 1;
	}
	if (cnt[n - 1] != 0) {
		cout << 0 << endl << "1 1" << endl;
		exit(0);
	}
}

int beauty_() {
	int mn = 10000000;
	for (int i = 0; i < n; ++i)
		if (cnt[i] < mn)
			mn = cnt[i];
	int res = 0;
	for (int i = 0; i < n; ++i)
		if (cnt[i] == mn)
			++res;
	return res;
}

int beauty(int l, int r) {
	int d;
	if (s[l] == '(')
		d = -2;
	else d = 2;
	int mn = 10000000;
	for (int i = 0; i < n; ++i)
		if (cnt[i] + ((l <= i && i < r) ? d : 0) < mn)
			mn = cnt[i] + ((l <= i && i < r) ? d : 0);
	int res = 0;
	for (int i = 0; i < n; ++i)
		if (cnt[i] + ((l <= i && i < r) ? d : 0) == mn)
			++res;
	return res;
}

signed main() {
	cin >> n;
	cin >> s;
	form();
	int mx_b = beauty_(), l = 0, r = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (s[i] == s[j]) continue;
			int b = beauty(i, j);
			if (mx_b < b) {
				mx_b = b;
				l = i; r = j;
			}
		}
	}
	cout << mx_b << endl << (l + 1) << " " << (r + 1) << endl;
	return 0;
}