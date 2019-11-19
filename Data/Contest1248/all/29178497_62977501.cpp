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
const int MOD = (int)1e9 + 7;
const int N = 100100;

int add(int a, int b) {
	if (a + b >= MOD) {
		return a + b - MOD;
	}
	return a + b;
}

int sub(int a, int b) {
	if (a - b < 0) {
		return a - b + MOD;
	}
	return a - b;
}

int mul(int a, int b) {
	return 1ll * a * b % MOD;
}

int f[N];

void precalc() {
	f[0] = 1;
	f[1] = 1;

	for (int i = 2; i < N; ++i) {
		f[i] = add(f[i - 1], f[i - 2]);
	}
}

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);

	precalc();

	printf("%d\n", mul(2, sub(add(f[n], f[m]), 1)));

	return 0;
}
