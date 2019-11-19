#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int a, b, c, d, k; scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		bool flg = false;
		for (int i = 0; i <= k; i++) {
			if (i * c >= a && (k - i) * d >= b) {
				flg = true, printf("%d %d\n", i, k - i);
				break;
			}
		}
		if (!flg) puts("-1");
	}
}