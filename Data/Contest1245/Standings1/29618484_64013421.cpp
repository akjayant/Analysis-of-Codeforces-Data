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
class UnionFind {
	mutable std::vector<int> vec;
public:
	UnionFind(const int size) : vec(size, -1) {};
	int find(int a) const {
		if (vec[a] < 0) return a;
		else return vec[a] = find(vec[a]);
	}
	bool same(int a, int b) const { return find(a) == find(b); }
	void unite(int a, int b) {
		a = find(a); b = find(b);
		if (a != b) {
			if (vec[a] < vec[b]) {
				vec[a] += vec[b];
				vec[b] = a;
			}
			else {
				vec[b] += vec[a];
				vec[a] = b;
			}
		}
	}
};
struct Coordinate {
	int x, y;
	int manhattan_distance(Coordinate that) const {
		return std::abs(x - that.x) + std::abs(y - that.y);
	}
};
int main() {
	std::cin.tie(0); std::cin.sync_with_stdio(false);
	int n; std::cin >> n;
	std::vector<Coordinate> cities(n); for (auto& c : cities) std::cin >> c.x >> c.y;
	std::vector<int> build_cost(n); for (auto& b : build_cost) std::cin >> b;
	std::vector<long long int> connect_cost(n); for (auto& k : connect_cost) std::cin >> k;
	auto comparator = [](const std::pair<std::pair<int, int>, long long int>& a, const std::pair<std::pair<int, int>, long long int>& b) {return a.second > b.second; };
	std::priority_queue<std::pair<std::pair<int, int>, long long int>, std::vector<std::pair<std::pair<int, int>, long long int>>, decltype(comparator)> queue(comparator);
	for (auto i = 0; i < n; ++i) {
		queue.emplace(std::make_pair(i, n), build_cost[i]);
		for (auto j = 0; j < i; ++j) {
			queue.emplace(std::make_pair(i, j), (connect_cost[i] + connect_cost[j]) * cities[i].manhattan_distance(cities[j]));
		}
	}
	UnionFind uft(n + 1);
	std::vector<int> for_build;
	std::vector<std::pair<int, int>> for_connect;
	long long int sum_cost = 0;
	for (auto i = 0; i < n; ++i) {
		while (uft.same(queue.top().first.first, queue.top().first.second)) queue.pop();
		auto top = queue.top();
		uft.unite(top.first.first, top.first.second);
		sum_cost += top.second;
		if (top.first.second == n) {
			for_build.push_back(top.first.first + 1);
		}
		else {
			for_connect.emplace_back(top.first.first + 1, top.first.second + 1);
		}
	}
	std::cout << sum_cost << '\n';
	std::cout << for_build.size() << '\n';
	if (!for_build.empty()) {
		for (auto i = 0; i < for_build.size(); ++i) {
			if (i != 0) std::cout << ' ';
			std::cout << for_build[i];
		}
		std::cout << '\n';
	}
	std::cout << for_connect.size() << '\n';
	if (!for_connect.empty()) {
		for (auto p : for_connect) {
			std::cout << p.first << ' ' << p.second << '\n';
		}
	}
}
