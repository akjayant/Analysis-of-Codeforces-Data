#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100;

char s[N + 3];
char ans[N + 3];
vector<char> whatever;

int main() {
	int t, n, win, a, b, c, ka, kb, kc, x, y, z, i;

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		scanf("%d%d%d", &a, &b, &c);
		scanf(" %s", s + 1);

		x = y = z = 0;

		for (i = 1; i <= n; i++) {
			x += s[i] == 'R';
			y += s[i] == 'P';
			z += s[i] == 'S';
		}

		ka = min(a, z);
		kb = min(b, x);
		kc = min(c, y);
		win = ka + kb + kc;
		
		for (i = 0; i < a - ka; i++) {
			whatever.push_back('R');
		}

		for (i = 0; i < b - kb; i++) {
			whatever.push_back('P');
		}

		for (i = 0; i < c - kc; i++) {
			whatever.push_back('S');
		}

		if (win >= (n + 1) / 2) {
			printf("YES\n");

			for (i = 1; i <= n; i++) {
				if (s[i] == 'R') {
					if (kb > 0) {
						ans[i] = 'P';
						kb--;
					}
					else {
						ans[i] = whatever.back();
						whatever.pop_back();
					}
				}
				else if (s[i] == 'P') {
					if (kc > 0) {
						ans[i] = 'S';
						kc--;
					}
					else {
						ans[i] = whatever.back();
						whatever.pop_back();
					}
				}
				else if (s[i] == 'S') {
					if (ka > 0) {
						ans[i] = 'R';
						ka--;
					}
					else {
						ans[i] = whatever.back();
						whatever.pop_back();
					}
				}
			}

			ans[n + 1] = '\0';

			printf("%s\n", ans + 1);
		}
		else {
			printf("NO\n");
		}

		whatever.clear();
	}

	return 0;
}
