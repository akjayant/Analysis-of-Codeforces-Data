#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	return b? gcd(b, a % b): a;
}

int t, a, b;

int main(){
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (gcd(a, b) > 1)
			cout << "Infinite\n";
		else
			cout << "Finite\n";
	}
	return 0;
}
