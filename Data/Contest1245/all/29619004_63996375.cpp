#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr), ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		int g = __gcd(a, b);
		if (g == 1) cout << "Finite\n";
		else cout << "Infinite\n";
	}
}
