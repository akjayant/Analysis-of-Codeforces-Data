#include<bits/stdc++.h>
using namespace std;

#define int long long 

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}
	int d = 2, iters = 0;
	while (n % d != 0 && iters < 10000000) {
		iters++;
		d++;
	}
	if (iters == 10000000) {
		cout << n << '\n';
		return 0;
	}
	while (n % d == 0) {
		n /= d;
	}
	cout << (n == 1 ? d : 1) << '\n';
	return 0;
}