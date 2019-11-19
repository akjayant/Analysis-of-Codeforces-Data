#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	int a, b, c, d, k;
	int x, y;
	ios :: sync_with_stdio(0);
	cin >> t;
	while(t--) {
		cin >> a >> b >> c >> d >> k;
		x = a / c, y = b / d;
		if(x * c < a) ++x;
		if(y * d < b) ++y;
		if(x + y <= k) {
			cout << x << ' ' << y << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}