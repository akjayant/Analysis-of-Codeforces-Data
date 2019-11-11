#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		if (gcd(a, b) == 1) cout << "Finite\n";
		else cout << "Infinite\n";
	}
}