#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1e3;
int T, n, a[N + 5];
char str[N + 5];

int main() {
	for (scanf("%d", &T); T--; ) {
		scanf("%d%s", &n, str + 1);
		int ans = 0, tmp = 0;
		for (int i = 1; i <= n; ++i) {
			if (str[i] == '1') ans = std::max(ans, std::max(i, n - i + 1)), tmp = 1;
		}
		printf("%d\n", std::max(n, tmp * 2 * std::max(ans, n - ans + 1)));
	}
	return 0;
}