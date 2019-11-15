#include <bits/stdc++.h>

using namespace std;

const int mod = (int )(1e9) + 7;

int ksm(int x, int y) {
	int sum = 1;
	for (; y; y >>= 1) {
		if (y & 1) sum = 1LL * sum * x % mod;
		x = 1LL * x * x % mod;
	}
	return sum;
}
int n, m;
int main( ) {
	scanf("%d %d", &n, &m);
	int tmp = (ksm(2, m) - 1 + mod);
	int tmp2 = ksm(tmp, n);
	printf("%d\n", tmp2);
	return 0;
}