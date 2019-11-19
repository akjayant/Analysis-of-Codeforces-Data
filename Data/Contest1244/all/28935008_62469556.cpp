#include <bits/stdc++.h>

typedef long long ll;

ll n, p, w, d;

ll gcd(ll a, ll b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main() {
	scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
	if (1ll * w * n < p || p % gcd(w, d)) {
		printf("-1\n");
		return 0;
	}
	ll t = p / w;
	for (ll i = std::max(0ll, t - 100000); i <= std::min(n, t + 100000); i++) {
		ll sc = i * w;
		if (sc <= p && (p - sc) % d == 0) {
			ll td = (p - sc) / d;
			if (i + td <= n) {
				printf("%I64d %I64d %I64d\n", i, td, n - i - td);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}
