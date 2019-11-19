#include <bits/stdc++.h>

using namespace std;

int t;
int a, b, c, d, k;

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d >> k;
		int tmpa = (a + c - 1) / c;
		int tmpb = (b + d - 1) / d;
		if (tmpa + tmpb > k) cout << "-1" << endl;
		else cout << tmpa << ' ' << tmpb << endl;
	}
	return 0;
}
