#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	else return gcd(b % a, a);
}

void solve() {
	int a, b;
	cin >> a >> b;
	if (gcd(a, b) == 1) {
		cout << "Finite" << "\n";
	} else {
		cout << "Infinite" << "\n";
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}