#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <climits>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <bitset>
#include <iostream>
#include <tuple>

typedef long long LL;

const int M = int(1e9) + 7;

int solve(int n, int m) {
	std::vector<int> ans(m);
	ans[0] = 1;
	if (m > 1) {
		ans[1] = 2;
	}
	for(int i = 2; i < m; ++i) {
		ans[i] = (ans[i - 1] + ans[i - 2]) % M;
	}
	return (2 * ans.back()) % M;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int r1 = solve(n, m);
	int r2 = solve(m, n);
	int ans = (r1 + r2) % M;
	printf("%d", (M + ans - 2) % M);
	return 0;
}