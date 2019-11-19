#include <bits/stdc++.h>
using namespace std;
int t;

int main () {
	cin >> t;
	while (t --) {
		int a, b, c, d, k;
		int x, y;
		cin >> a >> b >> c >> d >> k;
		x = (a + c - 1) / c;
		y = k - x;
		if (y * d < b) cout << -1 << endl;
		else cout << x << " " << y << endl; 
	}
	return 0;
}
