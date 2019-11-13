#include "bits/stdc++.h"
#define N 100
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll fpow(int a, int n) {
	ll ans = 1, tmp = a;
	while (n) {
		if (n & 1) ans = ans * tmp % MOD;
		tmp = tmp * tmp % MOD, n >>= 1;
	}
	return ans;
}
int main(int argc, char const *argv[]) {
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = fpow(fpow(2, m) - 1, n);
	if (ans < 0) ans += MOD;
	printf("%d\n", ans);
	return 0;
}