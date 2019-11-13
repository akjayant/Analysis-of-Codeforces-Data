#include <cstdio>
using namespace std;

const int MOD = 1000000007;
int n, m;

inline int ksm (int p, int x) {
	p = (p + MOD) % MOD;
	int s = 1;
	while (x) {
		if (x & 1) s = 1ll * s * p % MOD;
		p = 1ll * p * p % MOD;
		x >>= 1;
	}
	return s;
}

int main () {
    scanf ("%d %d", &n, &m);
    printf ("%d\n", ksm (ksm (2, m) - 1, n));
    
	return 0;
}