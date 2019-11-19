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
const int N = 100100;

int a[N];

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	std::sort(a, a + n);

	ll s1 = 0, s2 = 0;
	for (int i = 0; i < n; ++i) {
		if (i < n / 2) {
			s1 += a[i];
		} else {
			s2 += a[i];
		}
	}

	printf("%lld\n", s1 * s1 + s2 * s2);

	return 0;
}
