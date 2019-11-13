#include <bits/stdc++.h>

using namespace std;

long long a, b;

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (__gcd(a, b) > 1) {
			cout << "Infinite\n";
		} else cout << "Finite\n";
	}
	return 0;
}
