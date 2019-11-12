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
		std::vector<int> p1, p2;
		for (int i = 0; i < n; ++i) {
			if (s1[i] == s2[i]) continue;
			for (int j = i + 1; j < n; ++j) {
				if (s1[i] == s1[j]) {
					std::swap(s2[i], s1[j]);
					p1.push_back(j);
					p2.push_back(i);
					break;
				}
			}
			if (s1[i] == s2[i]) continue;
			for (int j = i + 1; j < n; ++j) {
				if (s1[i] == s2[j]) {
					std::swap(s1[n - 1], s2[j]);
					std::swap(s1[n - 1], s2[i]);
					p1.push_back(n - 1);
					p2.push_back(j);
					p1.push_back(n - 1);
					p2.push_back(i);
					break;
				}
			}
		}
		if (s1 == s2 && p1.size() <= 2 * n) {
			printf("Yes\n");
			printf("%d\n", (int)p1.size());
			for (int i = 0; i < p1.size(); ++i) {
				printf("%d %d\n", p1[i] + 1, p2[i] + 1);
			}
		} else {
			printf("No\n");
		}
	}
	return 0;
}