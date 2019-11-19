#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <tuple>
#include <bitset>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
#include <cassert>
struct Coordinate {
	int x, y;
	Coordinate succ(int count) const {
		if (y % 2 == 0) {
			auto nx = x - count;
			auto ny = y;
			if (nx < 0) {
				nx = -nx - 1;
				ny -= 1;
			}
			return Coordinate{ nx, ny };
		}
		else {
			auto nx = x + count;
			auto ny = y;
			if (nx > 9) {
				nx = 19 - nx;
				ny -= 1;
			}
			return Coordinate{ nx, ny };
		}
	}
};
int main() {
	std::cin.tie(0); std::cin.sync_with_stdio(false);
	std::vector<std::vector<int>> state(10, std::vector<int>(10));
	for (auto& line : state) for (auto& square : line) std::cin >> square;
	std::vector<std::vector<long double>> pure(10, std::vector<long double>(10, 0));
	std::vector<std::vector<long double>> memo(10, std::vector<long double>(10, 0));
	for (auto i = 1; i < 100; ++i) {
		int cy = i / 10;
		int cx = (cy % 2 == 0) ? (i % 10) : (9 - i % 10);
		Coordinate current{ cx, cy };
		memo[cy][cx] = 0;
		int count = 0;
		for (auto i = 1; i <= 6; ++i) {
			auto next = current.succ(i);
			if (next.y < 0) break;
			memo[cy][cx] += memo[next.y][next.x];
			++count;
		}
		memo[cy][cx] = memo[cy][cx] / count + 6.0 / count;
		pure[cy][cx] = memo[cy][cx];
		memo[cy][cx] = std::min(memo[cy][cx], pure[cy - state[cy][cx]][cx]);
	}
	std::cout << std::setprecision(10) << std::fixed << memo[9][0] << '\n';
}
