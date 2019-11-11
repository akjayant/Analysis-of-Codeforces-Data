#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (__gcd(a, b) > 1) {
			cout << "Infinite" << endl;
		} else {
			cout << "Finite" << endl;
		}
	}
}