#include <iostream>
#include <cstdio>

int res[301][301];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int count;
	std::cin >> count;

	int index = 1;
	for (int i = 1; i <= count; i++) /*col*/ {
		for (int j = 1; j <= count; j++) /*row*/ {
			if (i % 2 == 1) {
				res[j][i] = index++;
			}
			else {
				res[count - j + 1][i] = index++;
			}
		}
	}

	for (int i = 1; i <= count; i++) {
		for (int j = 1; j <= count; j++) {
			std::cout << res[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}