#include <iostream>
#include <cstdio>
#include <algorithm>

void run() {
	int a, b, c;
	std::cin >> a >> b >> c;

	int sum = 0, temp = std::min(b, c / 2);
	sum = temp * 3;

	b -= temp;
	temp = std::min(a, b / 2);
	sum += temp * 3;
	std::cout << sum << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int gp;
	std::cin >> gp;

	for (int i = 0; i < gp; i++) {
		run();
	}

	return 0;
}