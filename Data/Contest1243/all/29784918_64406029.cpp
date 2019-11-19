#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b) {
	while (b > 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main()
{
	long long n, check;
	cin >> n;
	check = n;
	int d = sqrt(n) + 0.5;
	for (int i = 2; i <= d; ++i)
		if (n % i == 0)
			check = gcd(gcd(check, i), n / i);
	cout << check << endl;
	return 0;
}