#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		if(gcd(a, b) == 1) puts("Finite");
		else puts("Infinite"); 
	}
	return 0;
}