#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int del1;


signed main() {
	cin >> n;
	int ans = n;
	int c = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			del1 = i;
			while (n % i == 0) {
				n = n / i;
			}
			c++;
			break;

		}
	}
	if (c == 1 && n > 1) {
		c++;
	}
	if (c == 0) {
		cout << ans;
		return 0;
	}
	if (c == 1) {
		cout << del1;
		return 0;
	}
	cout << 1;
}
