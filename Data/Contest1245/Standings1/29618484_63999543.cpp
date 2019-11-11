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
		int n, a, b, c; std::cin >> n >> a >> b >> c;
		std::string alice(n, '.');
		std::string bobs; std::cin >> bobs;
		int win_count = 0;
		for (auto i = 0; i < n; ++i) {
			switch (bobs[i]) {
			case 'R':
				if (b > 0) {
					++win_count;
					--b;
					alice[i] = 'P';
				}
				break;
			case 'P':
				if (c > 0) {
					++win_count;
					--c;
					alice[i] = 'S';
				}
				break;
			case 'S':
				if (a > 0) {
					++win_count;
					--a;
					alice[i] = 'R';
				}
				break;
			default: throw 0;
			}
		}
		if ((n + 1) / 2 > win_count) {
			std::cout << "NO\n";
		}
		else {
			std::cout << "YES\n";
			for (auto i = 0; i < n; ++i) {
				if (alice[i] == '.') {
					if (a > 0) {
						--a;
						alice[i] = 'R';
					}
					else if (b > 0) {
						--b;
						alice[i] = 'P';
					}
					else {
						--c;
						alice[i] = 'S';
					}
				}
			}
			std::cout << alice << '\n';
		}
	}
}