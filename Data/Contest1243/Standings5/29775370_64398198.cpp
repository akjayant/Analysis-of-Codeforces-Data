#include <bits/stdc++.h>
using namespace std;

long long n, cnt;

int main() {
	cin >> n;
	for (long long i = 2; i * i <= n; i++)
		if (n % i == 0) {
			if (cnt) {
				cout << 1;
				return 0;
			}
			cnt = i;
			while (n % i == 0) {
				n /= i;
			}
		}
	if (cnt && n > 1) {
		cout << 1;
		return 0;
	}
	if (!cnt)
		cnt = n;
	cout << cnt;
	return 0;
}
