#include <algorithm>
#include <iostream>
int a[233333];
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	int n; std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	std::sort(a, a + n);
	int s1 = 0, s2 = 0;
	for (int i = 0; i < n >> 1; ++i) {
		s1 += a[i];
	}
	for (int i = n >> 1; i < n; ++i) {
		s2 += a[i];
	}
	std::cout << 1ll * s1 * s1 + 1ll * s2 * s2 << std::endl;
}