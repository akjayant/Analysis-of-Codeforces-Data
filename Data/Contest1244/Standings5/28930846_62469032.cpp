#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
char s[maxn];
int main() {
	int T;	scanf("%d", &T);
	while (T--) {
		int n;	scanf("%d", &n);
		scanf("%s", s + 1);
		int ans = n;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1') {
				ans = max(ans, 2 * (n - i + 1));
				break;
			}
		}
		for (int i = n; i >= 1; i--) {
			if (s[i] == '1') {
				ans = max(ans, 2 * i);
				break;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}