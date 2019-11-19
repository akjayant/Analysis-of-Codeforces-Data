#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
signed main() {
	int n, p, w, d;
	cin >> n >> p >> w >> d;
	bool ans = 0;
	int i = 1;
	if (p % w == 0 && p / w <= n) {
		cout << p/w << " " <<0 << " " << n - p / w;
		return 0;
	}
	for (i = 1; i < 100002 && (p-i*d)>=0 ; i++) {
		if ((p - d * i) % w == 0) {
			int c = (p - d * i) / w;
			if (c + i <= n) {
				cout << c << " " << i << " " << n - c - i;
				return 0;
			}
			else {
				cout << -1;
				return 0;
			}

		}
	}
	cout << -1;
	return 0;
}