#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
int n, m;

int powmod(int b, int e)
{
	if(!e)
		return 1;
	if(e & 1)
		return (1LL * b * powmod(b, e - 1)) % MOD;
	int aux = powmod(b, e >> 1);
	return (1LL * aux * aux) % MOD;
}

int main()
{
	scanf("%d %d", &n, &m);
	printf("%d\n", powmod(powmod(2, m) - 1, n));
}