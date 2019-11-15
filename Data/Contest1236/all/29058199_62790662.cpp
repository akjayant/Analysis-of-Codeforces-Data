#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;
const int mod = 1e9+7;

ll fexp(ll b, ll e) {
	ll ans = 1;
	while(e) {
		if(e & 1) ans = ans * b % mod;
		b = b * b % mod;
		e /= 2;
	}
	return ans;
}

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	printf("%lld\n", fexp(fexp(2, m) - 1, n));
}
