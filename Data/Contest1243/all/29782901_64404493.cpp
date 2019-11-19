#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	long long int n;
	cin >> n;

	long long int gcd = n;
	while (n % 2 == 0)
	{
	    long long int z = 2;
		gcd =__gcd(z, gcd);
		n = n / 2;
	}

	long long int x = sqrt(n);
	for (long long int i = 3; i <= x; i = i + 2)
	{
		while (n % i == 0)
		{
			gcd = __gcd(gcd, i);
			n = n / i;
		}
	}

	if (n > 2)
		gcd = __gcd(gcd, n);

	cout << gcd;
}