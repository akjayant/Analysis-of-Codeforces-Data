#include <bits/stdc++.h>

const int32_t MOD = 1e9 + 7;

int32_t fast_pow(int32_t x, int32_t p) {
	if(p == 1) {
		return x;
	}
	else if(p % 2 == 0) {
		int32_t aux = fast_pow(x, p / 2);
		return ((int64_t) aux * aux) % MOD;
	}
	else {
		return ((int64_t) fast_pow(x, p - 1) * x) % MOD;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int32_t n, m;
	std::cin >> n >> m;

	int32_t aux = (fast_pow(2, m) - 1 + MOD) % MOD;

	std::cout << fast_pow(aux, n) << '\n';
}

