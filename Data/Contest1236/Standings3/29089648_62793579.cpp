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
int main() {
	std::cin.tie(0); std::cin.sync_with_stdio(false);
	int n; std::cin >> n;
	std::vector<std::vector<int>> result(n);
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			if (i % 2 == 0) {
				result[j].push_back(i * n + j + 1);
			}
			else {
				result[n - j - 1].push_back(i * n + j + 1);
			}
		}
	}
	for (auto& line : result) {
		for (auto i = 0; i < line.size(); ++i) {
			if (i != 0) std::cout << ' ';
			std::cout << line[i];
		}
		std::cout << '\n';
	}
}
