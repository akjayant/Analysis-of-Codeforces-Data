#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;

long long int binpow (long long int a, long long int n) {
	long long int res = 1;
	while (n)
		if (n & 1) {
			res *= a;
			res = res % mod;
			--n;
		}
		else {
			a *= a;
			a %= mod;
			n >>= 1;
		}
	return res %  mod;
}

int main()
{
    long long int a, b;
    cin >> a >> b;
    cout << binpow((binpow(2, b) - 1), a);
}
