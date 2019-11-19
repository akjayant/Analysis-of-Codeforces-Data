#include <iostream>
constexpr int mod = 1000000007;
inline void up(int& x) {
	x += x >> 31 & mod;
}
int n, m;
void calc(int x) {
	if (m == 1) {
		std::cout << 2 * x % mod << std::endl;
		return;
	}
	up(x += 1 - mod);
	int f1 = 1, f2 = 1, f3 = 0;
	for (int i = 2; i < m; ++i) {
		up(x += f2 - mod);
		up(f3 = f1 + f2 - mod);
		f1 = f2, f2 = f3;
	}
	std::cout << 2 * x % mod << std::endl;
}
int main() {
	std::cin >> n >> m;
	if (n == 1) return calc(1), 0;
	int f1 = 1, f2 = 2, f3 = 0;
	for (int i = 2; i < n; ++i) {
		up(f3 = f1 + f2 - mod);
		f1 = f2, f2 = f3;
	}
	calc(f2);
}