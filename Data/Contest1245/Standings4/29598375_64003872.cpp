#include <bits/stdc++.h>

using namespace std;
const int N = 222 + 3;
char s[N], res[N];
int n, a, b, c;
void solve() {
	res[n] = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'R') {
			if (b) {
				--b;
				res[i] = 'P';
			} else {
				res[i] = '.';
			}
		} else if (s[i] == 'P') {
			if (c) {
				--c;
				res[i] = 'S';
			} else {
				res[i] = '.';
			}
		} else if (s[i] == 'S') {
			if (a) {
				--a;
				res[i] = 'R';
			} else {
				res[i] = '.';
			}
		} else {
			assert(false);
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d %s", &n, &a, &b, &c, s);
		solve();
		int t = n - (a + b + c);
		if (t >= (n + 1) / 2) {
			puts("YES");
			for (int i = 0; i < n; ++i) {
				if (res[i] == '.') {
					if (a) {
						--a;
						res[i] = 'R';
					} else if (b) {
						--b;
						res[i] = 'P';
					} else if (c) {
						--c;
						res[i] = 'S';
					} else {
						assert(false);
					}
				}
			}
			printf("%s\n", res);
		} else {
			puts("NO");
		}
	}
	return 0;
}
