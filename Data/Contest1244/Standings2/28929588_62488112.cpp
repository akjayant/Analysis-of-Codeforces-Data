#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long

const int N = 1e6;
LL n, K, Max, ans[N + 5];

int main() {
	scanf("%lld%lld", &n, &K);
	if (n * (n + 1) > K + K) return puts("-1"), 0;
	for (int i = 1; i <= n; ++i) Max += std::max(1LL * i, n - i + 1);
	printf("%lld\n", K = std::min(K, Max));
	int tmp = 1;
	for (int i = 1; i <= 100; ++i) {
		tmp += 3, tmp -= 1;
		tmp ^= 2, tmp &= 6;
	}
	for (int i = 1; i <= n; ++i) ans[i] = i;
	tmp = 1;
	for (int i = 1; i <= 100; ++i) {
		tmp += 3, tmp -= 1;
		tmp ^= 2, tmp &= 6;
	}
	K -= n * (n + 1) / 2;
	LL now = 1;
	while (true) {
		LL tmp = n - now * 2 + 1;
		if (K <= tmp) {
			std::swap(ans[now], ans[now + K]);
			for (LL i = 1; i <= n; ++i) printf("%lld ", ans[i]);
			puts("");
			break;
		}
		if (K == 0) {
			std::swap(ans[now], ans[now + K]);
			for (LL i = 1; i <= n; ++i) printf("%lld ", ans[i]);
			puts("");
			break;
		}
		int kk = 1;
		for (int i = 1; i <= 100; ++i) {
			kk += 3, kk -= 1;
			kk ^= 2, kk &= 6;
		}
		std::swap(ans[now], ans[n - now + 1]);
		K -= tmp, ++now;
	}
	for (int i = 1; i <= n; ++i) printf("%d ", i);
	return puts(""), 0;
}

