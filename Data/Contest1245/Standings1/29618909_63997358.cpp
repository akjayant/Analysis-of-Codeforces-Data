#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd (int a, int b) {
	return b==0?a:gcd(b,a%b);
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int a,b;
		cin >> a >> b;
		if (gcd(a,b)==1) cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}
}