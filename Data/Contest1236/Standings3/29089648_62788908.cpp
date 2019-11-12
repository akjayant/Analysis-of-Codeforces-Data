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
constexpr long long int MOD = 1000000007;
long long int power(const long long int base, const int exp) {
	switch (exp) {
	case 0: return 1;
	case 1: return base % MOD;
	default: return power(base * base % MOD, exp / 2) * power(base, exp % 2) % MOD;
	}
}
int main() {
	std::cin.tie(0); std::cin.sync_with_stdio(false);
	int present, box; std::cin >> present >> box;
	std::cout << power((power(2, box) + MOD - 1) % MOD, present) << '\n';
}
