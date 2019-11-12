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
	int t; std::cin >> t;
	for (auto _i = 0; _i < t; ++_i) {
		int a, b, c; std::cin >> a >> b >> c;
		auto second = std::min(b, c / 2);
		auto first = std::min(a, (b - second) / 2);
		std::cout << (first + second) * 3 << '\n';
	}
}
