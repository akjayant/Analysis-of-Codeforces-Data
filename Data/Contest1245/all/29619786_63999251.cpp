#include <cstdio>
#include <iostream>

using namespace std;

int T, x, y;

int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a%b);
}

int main() {
	cin >> T;
	while(T--) {
		cin >> x >> y;
		if(gcd(x, y) == 1) cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}
	return 0;
}