#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int32_t t;
	std::cin >> t;

	for(int32_t cs = 1; cs <= t; cs++) {
		int32_t a, b, c;
		std::cin >> a >> b >> c;
	
		int32_t ans = 0;
		for(int32_t i = 0; i <= a; i++) {
			for(int32_t j = 0; j <= b; j++) {
				for(int32_t p = 0; p <= c; p += 2) {
					if(2 * i + p / 2 != j) {
						continue;
					}

					ans = std::max(ans, i + j + p);
				}
			}
		}

		std::cout << ans << '\n';
	}
}

