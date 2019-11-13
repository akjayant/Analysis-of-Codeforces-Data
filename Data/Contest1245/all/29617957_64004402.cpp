#include <iostream>

using namespace std;

int __gcd(int a, int b) {
	if (!b)
		return a;
	return __gcd(b, a % b);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b, flag = 0;
		cin >> a >> b;
		if (__gcd(a, b) == 1)
			puts("Finite");
		else
			puts("Infinite");
	}
	return 0;
}
