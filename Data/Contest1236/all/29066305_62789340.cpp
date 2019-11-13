#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = (LL)1e9 + 7;

LL fp(LL a, LL n) {
	LL ans = 1, t = a;
	while(n) {
		if(n & 1) ans = ans * t % MOD;
		t = t * t % MOD;
		n >>= 1;
	}
	return ans;
}

int main() {
	LL n, m;
	cin >> n >> m;
	cout << fp((fp(2, m) - 1 + MOD) % MOD, n);
}
