#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;	scanf("%d", &T);
	while (T--) {
		int a, b, c, d, k;	scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		bool flag = false;
		for (int x = 0; x <= k; x++) {
			int y = k - x;
			if (a <= c * x && b <= d * y) {
				printf("%d %d\n", x, y);
				flag = true;
				break;
			}
		}
		if (!flag) {
			printf("-1\n");
		}
	}
	
	return 0;
}