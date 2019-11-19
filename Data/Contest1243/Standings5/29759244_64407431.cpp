#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAXN 1010
typedef long long ll;

ll nok(ll a, ll b) {//a>b
	if (a < b)
		return nok(b, a);
	if (b < 1)
		return a;
	return nok(b, a % b);
}


int main()
{
	ll n;
	scanf("%lld", &n);
	ll k = n;
	for (ll i = 2; i*i <= n; i++)
	{
		if (n % i == 0) {
			k = nok(nok(k, i), n / i);
		}
	}

	printf("%lld", k);
}
