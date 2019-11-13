#include <iostream>
#include <cstdio>

using lint = long long;

const lint mod = 1e9 + 7;

lint quickPow(const lint& base, lint pow) {
	lint res = 1, temp = base;
	while (pow) {
		if (pow & 1) {
			res = (res * temp) % mod;
		}

		temp = (temp * temp) % mod;
		pow >>= 1;
	}

	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	lint type, count;
	std::cin >> type >> count;

	std::cout << quickPow((quickPow(2, count) - 1 + mod) % mod, type) << std::endl;

	return 0;
}