#include <iostream>
using namespace std;
int a, b;
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main() {
	int T;
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		if (gcd(a, b) == 1) cout << "Finite\n";
		else cout << "Infinite\n";
	}

	return 0;
}