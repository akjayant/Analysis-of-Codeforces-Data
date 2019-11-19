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

int main() {
	int n;
	scanf("%d", &n);
	std::vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}
	std::sort(a.begin(), a.end());
	LL sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; ++i) {
		if (i < n / 2) {
			sum1 += a[i];
		} else {
			sum2 += a[i];
		}
	}
	printf("%I64d", sum1 * sum1 + sum2 * sum2);
	return 0;
}