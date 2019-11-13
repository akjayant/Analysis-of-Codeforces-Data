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
		char b[10001];
		scanf("%10000s", b);
		std::string s1(b);
		scanf("%10000s", b);
		std::string s2(b);
		int prev = -1;
		for (int i = 0; i < n; ++i) {
			if (s1[i] != s2[i]) {
				if (prev == -1) {
					prev = i;
				} else {
					std::swap(s1[prev], s2[i]);
					break;
				}
			}
		}
		if (s1 == s2) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}