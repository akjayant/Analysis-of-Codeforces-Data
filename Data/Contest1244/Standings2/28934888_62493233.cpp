#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
	int maxx = 0;
int ans[2000010];
signed main() {
    scanf("%lld %lld",&n,&k);
    if (n * (n + 1) > k * 2) {puts("-1");return 0;}
	for (int i = 1; i <= n; i++) ans[i] = i, maxx += max(i, n - i + 1);
	k = min(k, maxx);
	printf("%lld\n", k);
	for (int i = 1; i <= n; i++) printf("%lld ", i);puts("");
    k -= n * (n + 1) / 2;
	for (int i = 1; ; i++) {
		int p = n - i * 2 + 1;
		if (k <= p || !k) {
			swap(ans[i], ans[i + k]);
			for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
            printf("\n");
        	exit(0);
		} else k -= p, swap(ans[i], ans[n - i + 1]);
	}
	return 0;
}
