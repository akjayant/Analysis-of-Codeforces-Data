#include <cstdio>
#include <algorithm>
#include <cstring>

const int N = 1e2 + 10;

int n, a, b, c;
char str[N], ans[N];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d%s", &n, &a, &b, &c, str);
		memset(ans, 0, sizeof(ans));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (str[i] == 'S' && a > 0) {
				ans[i] = 'R';
				a--;
				cnt++;
			}
			if (str[i] == 'R' && b > 0) {
				ans[i] = 'P';
				b--;
				cnt++;
			}
			if (str[i] == 'P' && c > 0) {
				ans[i] = 'S';
				c--;
				cnt++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (ans[i] == 0) {
				if (a > 0) ans[i] = 'R', a--;
				else if (b > 0) ans[i] = 'P', b--;
				else ans[i] = 'S', c--;
			}
		}
		if (cnt * 2 >= n) printf("YES\n%s\n", ans);
		else puts("NO");
	}
	return 0;
}