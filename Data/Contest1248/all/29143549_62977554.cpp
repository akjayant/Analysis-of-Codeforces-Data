#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt[10];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		cnt[0] = cnt[1] = 0;
		scanf("%d", &n);
		long long ans = 0;
		for(int i = 1; i <= n; ++i) {
			int x; scanf("%d", &x);
			++cnt[x % 2];
		}
		scanf("%d", &m);
		for(int i = 1; i <= m; ++i) {
			int x; scanf("%d", &x);
			ans += cnt[x % 2];
		}
		printf("%lld\n", ans);
	}
	return 0;
}