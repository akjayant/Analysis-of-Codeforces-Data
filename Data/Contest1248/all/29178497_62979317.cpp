// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl;
#define fastIO std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);

typedef long long ll;
typedef long double ld;

std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());

const double PI = atan2(0., -1.);
const int INF = 0x3f3f3f3f;

int cnt1[2], cnt2[2];

int main(void) {
	int t;
	scanf("%d", &t);

	while (t--) {
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d", &a);
			++cnt1[abs(a) % 2];
		}

		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			int a;
			scanf("%d", &a);
			++cnt2[abs(a) % 2];
		}

		printf("%lld\n", 1ll * cnt1[0] * cnt2[0] + 1ll * cnt1[1] * cnt2[1]);
	}

	return 0;
}
