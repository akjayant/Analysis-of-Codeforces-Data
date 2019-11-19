#include <bits/stdc++.h>
using namespace std;

long long n, gcd;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	gcd = n;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			gcd = __gcd(gcd, __gcd(n / i, i));
		}
	}

	cout << gcd << '\n';

	return 0;
}