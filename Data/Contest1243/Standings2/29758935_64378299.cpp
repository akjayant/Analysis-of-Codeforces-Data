#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 3;
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
		int i = -1, j = -1;
		bool valid = true;
		for (int k = 0; k < n; ++k) {
			if (a[k] != b[k]) {
				if (~i && ~j)
					valid = false;
				else if (~i)
					j = k;
				else
					i = k;
			}
		}
		if (!valid) {
			puts("No");
			continue;
		}
		if (~i && ~j) {
			swap(a[i], b[j]);
			if (strcmp(a, b) == 0) {
				puts("Yes");
				continue;
			}
			swap(a[i], b[j]);
			
			swap(a[j], b[i]);
			if (strcmp(a, b) == 0) {
				puts("Yes");
				continue;
			}
			puts("No");
		} else if (~i) {
			puts("No");
		} else {
			puts("Yes");
		}
	}
	return 0;
}
