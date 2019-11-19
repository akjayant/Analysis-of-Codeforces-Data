#include <bits/stdc++.h>

using namespace std;
const int N = 55 + 3;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	long long n;
	scanf("%lld", &n);
	long long res = n, val = n;
	for (int i = 2; 1LL * i * i <= n; ++i) {
		if (n % i == 0) {
			if (res == val) {
				res = i;
			} else {
				res = 1;
				break;
			}
			while (n % i == 0)
				n /= i;
		}
	}
	if (n != 1) {
		if (res == val) {
			res = n;
		} else {
			res = 1;
		}
	}
	printf("%lld\n", res);
	return 0;
}
