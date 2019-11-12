#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <tuple>
#include <vector>
#include <bitset>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int n;
		scanf("%d", &n);
		std::vector<int> a(n);
		for (int& x : a) {
			scanf("%d", &x);
		}
		std::sort(a.begin(), a.end());
		int ans = 0;
		for (int i = n - 1; i >= 0; --i) {
			ans = std::max(ans, std::min(a[i], n - i));
		}
		printf("%d\n", ans);
	}
	return 0;
}