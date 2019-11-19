#include <bits/stdc++.h>
using namespace std;

int main (void) {
	long long n;
	cin >> n;
	int cnt = 0;
	long long minDiv = 1e9+7;
	bool oneDiv = true;

	for (long long i = 1LL; i * i <= n; ++i) {
		if (n%i == 0) {
			if (n/i == i)
				++cnt;
			else
				cnt = cnt + 2;

			if (i != 1) {
				minDiv = min(i, minDiv);
			}
		}
	}

	long long ans;

	if (n == 1) {
		ans = 1;
	} else if (cnt == 2) {
		ans = n;
	} else {
		while (n % minDiv == 0) {
			n /= minDiv;
		}

		if (n != 1)
			oneDiv = false;

		ans = (oneDiv ? minDiv : 1);
	}

	cout << ans << "\n";
}