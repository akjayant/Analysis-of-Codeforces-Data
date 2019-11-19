#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int u = a / c;
		if (a % c != 0) u++;
		int v = b / d;
		if (b % d != 0) v++;
		if (u + v > k) cout << - 1 << '\n';
		else cout << u << ' ' << v << '\n';
	}
	return 0;
}
