#include <bits/stdc++.h>

using namespace std;
const int N = 55 + 3;
int n;
char a[N], b[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %s %s", &n, a, b);
		vector<pair<int, int>> res;
		for (int i = 0; i < n; ++i) {
			if (a[i] != b[i]) {
				bool found = false;
				for (int j = i + 1; !found && j < n; ++j) {
					if (b[j] == a[i]) {
						swap(a[i], b[i]);
						res.emplace_back(i + 1, i + 1);
						
						swap(a[i], b[j]);
						res.emplace_back(i + 1, j + 1);
						found = true;
					}
				}
				for (int j = i + 1; !found && j < n; ++j) {
					if (b[j] == b[i]) {
						swap(a[i], b[j]);
						res.emplace_back(i + 1, j + 1);
						found = true;
					}
				}
				for (int j = i + 1; !found && j < n; ++j) {
					if (a[j] == a[i]) {
						swap(b[i], a[j]);
						res.emplace_back(j + 1, i + 1);
						found = true;
					}
				}
			}
		}
		if (strcmp(a, b) == 0) {
			puts("Yes");
			printf("%d\n", (int) res.size());
			for (auto p: res) {
				printf("%d %d\n", p.first, p.second);
			}
		} else {
			puts("No");
		}
	}
	return 0;
}
