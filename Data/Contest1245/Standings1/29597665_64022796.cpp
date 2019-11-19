#include <bits/stdc++.h>

const int N = 10;
int a[N][N];
std::pair<int, int> next(std::pair<int, int> t) {
	int x = t.first, y = t.second;
	if (x == 0 && y == 0) return { -1, -1 };
	if (x & 1) { // right
		++y;
		if (y >= 10) y = 9, --x;
	} else {
		--y;
		if (y < 0) y = 0, --x;
	}
	return {x, y};
}
std::pair<int, int> next(std::pair<int, int> t, int k) {
	return k ? next(next(t, k - 1)) : t;
}
typedef long double LD;
std::map<std::pair<int, int>, LD> dp;
LD dfs(std::pair<int, int> t) {
	if (dp.count(t)) return dp[t];
	LD ret = 6;
	for (int d = 1; d <= 6; ++d) {
		std::pair<int, int> goal = next(t, d);
		LD min = std::min(dfs(goal), dfs({goal.first - a[goal.first][goal.second], goal.second}));
		ret += min;
	}
	return dp[t] = ret / 6;
}
int main() {
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			std::cin >> a[i][j];
	dp[{0, 0}] = 0;
	for (int i = 1; i < 6; ++i)
		dp[{0, i}] = 6;
	std::cout << std::fixed << std::setprecision(10) << dfs({9, 0}) << '\n';
	return 0;
}
