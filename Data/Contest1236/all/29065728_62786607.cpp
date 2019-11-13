#include <stdio.h>
int T, a, b, c;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &a, &b, &c);
		int t3 = c/2, ans = 0;
		if (b > t3) {
			ans += t3*3; b-=t3;
		} else {
			ans += b*3; b=0;
		}
		int t2 = b/2;
		if (a > t2) {
			ans += t2*3;
		} else {
			ans += a*3;
		}
		printf("%d\n", ans);
	}
	return 0;
}
