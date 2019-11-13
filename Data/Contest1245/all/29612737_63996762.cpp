#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int gd = __gcd(a, b);
		if (gd == 1) {
			cout << "Finite\n";
		}
		else {
			cout << "Infinite\n";
		}		
	}
	return 0;
}
