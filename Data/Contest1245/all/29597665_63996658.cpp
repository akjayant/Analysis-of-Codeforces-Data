#include <bits/stdc++.h>

int n;
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	int tc, a, b; std::cin >> tc;
	while (tc--)
		std::cin >> a >> b, std::cout << (std::__gcd(a, b) == 1 ? "finite" : "infinite") << '\n';
	return 0;
}
