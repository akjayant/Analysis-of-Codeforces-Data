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
int main(){
	constexpr long long int MOD = 1000000007;
	std::cin.tie(0); std::cin.sync_with_stdio(false);
	std::string str; std::cin >> str;
	if (std::any_of(str.begin(), str.end(), [](const char c) {return c == 'm' || c == 'w'; })) {
		std::cout << "0\n";
		return 0;
	}
	std::vector<long long int> memo(str.size() + 1, 0);
	memo[0] = memo[1] = 1;
	for (auto i = 1; i < str.size(); ++i) {
		if (str[i] == 'u' && str[i - 1] == 'u') {
			memo[i + 1] = (memo[i] + memo[i - 1]) % MOD;
		}
		else if (str[i] == 'n' && str[i - 1] == 'n') {
			memo[i + 1] = (memo[i] + memo[i - 1]) % MOD;
		}
		else {
			memo[i + 1] = memo[i];
		}
	}
	std::cout << memo.back() << '\n';
}
