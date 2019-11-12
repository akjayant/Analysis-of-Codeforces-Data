#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

char s[N], t[N];

int main (void) {
	int kase;
	scanf("%d", &kase);
	while (kase--) {
		int n;
		scanf("%d", &n);
		scanf("%s%s", s + 1, t + 1);
		int x = 0, y = 0, ok = 1;
		for (int i = 1; i <= n; i++) {
			if (s[i] != t[i]) {
				if (!x) x = i;
				else if (!y) y = i;
				else ok = 0;
			}
		}
		if (!ok) {
			puts("No");
		} else if (s[x] != s[y] || t[x] != t[y]) {
			puts("No");
		} else {
			puts("Yes");
		}
	}
}