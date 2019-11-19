#include <bits/stdc++.h>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b, c, d, k;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		if (a % c == 0) a = a / c;
		else a = a / c + 1;
		if (b % d == 0) b = b / d;
		else b = b / d + 1;
		if (a + b <= k) printf("%d %d\n", a, b);
		else printf("-1\n");
	}
	return 0;
}
