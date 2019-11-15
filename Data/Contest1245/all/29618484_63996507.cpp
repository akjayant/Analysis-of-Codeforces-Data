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
int gcd(const int a, const int b) {
	return (b == 0) ? a : gcd(b, a % b);
}
int main(){
	std::cin.tie(0); std::cin.sync_with_stdio(false);
	int t; std::cin >> t;
	for (auto i = 0; i < t; ++i) {
		int a, b; std::cin >> a >> b;
		if (gcd(a, b) == 1) {
			std::cout << "Finite\n";
		}
		else {
			std::cout << "Infinite\n";
		}
	}
}