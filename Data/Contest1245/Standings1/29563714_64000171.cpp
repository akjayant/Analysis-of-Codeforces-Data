#include <bits/stdc++.h>
using namespace std;
int nTest;
int a;
int b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> nTest;
	for(int iTest = 1; iTest <= nTest; iTest++) {
		cin >> a >> b;
		if(__gcd(a, b) == 1) {
			cout << "Finite\n";
		}
		else {
			cout << "Infinite\n";
		}
	}
	return 0;
}