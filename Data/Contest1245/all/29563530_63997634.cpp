#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if(a == 0) {
		return b;
	}
	return gcd(b%a, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for(int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;

		if(gcd(a, b) == 1) {
			cout << "Finite" << endl;
		}
		else {
			cout << "Infinite" << endl;
		}
	}

	return 0;
}
