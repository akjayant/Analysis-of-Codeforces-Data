#include <iostream>
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	int t; std::cin >> t;
	while (t --> 0) {
		int a[] = {0, 0}, b[] = {0, 0};
		int n; std::cin >> n;
		for (int i = 1; i <= n; ++i) {
			int x; std::cin >> x;
			++a[x & 1];
		}
		int m; std::cin >> m;
		for (int i = 1; i <= m; ++i) {
			int x; std::cin >> x;
			++b[x & 1];
		}
		std::cout << 1ll * a[0] * b[0] + 1ll * a[1] * b[1] << '\n';
	}
}