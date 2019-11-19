#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define int long long

template <typename Tp>
inline void read(Tp &x) {
    x = 0;
    bool f = true; char ch = getchar();
    for ( ; ch < '0' || ch > '9'; ch = getchar()) f ^= ch == '-';
    for ( ; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch ^ 48);
    x = f ? x : -x;
}

const int N = 1e6 + 7;

int n, k;
int ans[N];

inline void init() {
	int maxx = 0;
	for (int i = 1; i <= n; ++i) ans[i] = i, maxx += std::max(i, n - i + 1);
	k = std::min(k, maxx);
	printf("%lld\n", k);
	for (int i = 1; i <= n; ++i) printf("%lld ", i);
    printf("\n");
}

inline void solve() {
    k -= n * (n + 1) / 2;
	for (int i = 1; ; ++i) {
		int p = n - i * 2 + 1;
		if (k <= p || !k) {
			std::swap(ans[i], ans[i + k]);
			for (int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
            printf("\n");
			return;
		} else k -= p, std::swap(ans[i], ans[n - i + 1]);
	}
}

signed main() {
    read(n), read(k);
    if (n * (n + 1) > k * 2) return printf("-1\n"), 0;
	init();
    solve();
	return 0;
}