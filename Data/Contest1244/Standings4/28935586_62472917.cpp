#include <bits/stdc++.h>
using namespace std;
int t;

int main () {
	cin >> t;
	while (t --) {
		int n;
		string s;
		cin >> n >> s;
		int mx = 0, mn = n;
		int flg = false;
		for (int i = 1; i <= n; i ++) {
			if (s[i-1] == '1') flg = true, mx = max (mx, i), mn = min (mn, i);
		}
		cout << max (n, !flg ? -1 : max (mx << 1, (n - mn+1) << 1)) << endl;
	}
	return 0;
}
