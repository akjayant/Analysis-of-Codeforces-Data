#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;


long long gcd (long long a, long long b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

int main()
{
	long long n;
	cin >> n;
	long long curgcd = n;
	for(long long i = 2; i <= (long long)(sqrt(n)); i++)
	{
		if( n % i == 0)
		{
			curgcd = gcd(max(curgcd, i), min(curgcd, i));
			curgcd = gcd(max(curgcd, n / i), min(curgcd, n / i));
		}

	}
	cout << curgcd;
	return 0;
}