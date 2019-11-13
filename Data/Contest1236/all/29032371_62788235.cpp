#include <bits/stdc++.h>
using namespace std;

long long const m = 1000000007;

long long bin_pow(long long num, long long x)
{
	if(x == 0) return 1;
	if(x == 1) return num;
	long long p = bin_pow(num, x / 2);
	if(x % 2 == 0) return (p * p % m);
	else return (p * p % m) * num % m;
}

int main()
{
	long long a, b;
	cin >> a >> b;
	cout << bin_pow(bin_pow(2, b) - 1, a);
	return 0;
}