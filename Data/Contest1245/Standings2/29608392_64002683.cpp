#include <bits/stdc++.h>
using namespace std;

char d[1100], ans[1100];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, a, b, c, aa = 0, bb = 0, cc = 0;
		scanf("%d", &n);
		scanf("%d%d%d", &a, &b, &c);
		scanf(" %s", d);
		for (int i = 0; i < n; i++) {
			if (d[i] == 'R') aa++;
			if (d[i] == 'P') bb++;
			if (d[i] == 'S') cc++;
		}
		int flag = 0, flag2 = 0;
		flag = min(a, cc) + min(b, aa) + min(c, bb);
		flag2 = min(aa, b) + min(bb, a) + min(cc, b);
		if (flag * 2 < n) {
			puts("NO");
		} else {
			puts("YES");
			for (int i = 0; i < n; i++) {
				ans[i] = ' ';
			}
			for (int i = 0; i < n; i++) {
				if (d[i] == 'R' && b > 0) {
					b--;
					ans[i] = 'P';
				}
				if (d[i] == 'P' && c > 0) {
					c--;
					ans[i] = 'S';
				}
				if (d[i] == 'S' && a > 0) {
					a--;
					ans[i] = 'R';
				}
			}
			for (int i = 0; i < n; i++) {
				if (ans[i] == ' ') {
					if (a > 0) {
						ans[i] = 'R'; a--;
					} else if (b > 0) {
						ans[i] = 'P'; b--;
					} else if (c > 0) {
						ans[i] = 'S'; c--;
					}
				}
			}
			for (int i = 0; i < n; i++) printf("%c", ans[i]); puts("");
		}
	}
	return 0;
}