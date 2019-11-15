#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef _CONSOLE
	freopen("t.in", "r", stdin);
#endif

	const int mod = 1e9 + 7;
	auto mypow = [&](long long a, long long e) {
		long long ans = 1;
		while (e) {
			if (e & 1) ans = (ans * a) % mod;
			a = (a * a) % mod;
			e >>= 1;
		}
		return ans;
	};
	long long n, m;
	scanf("%lld %lld", &n, &m);
	printf("%lld", mypow(mypow(2, m) - 1, n));
}