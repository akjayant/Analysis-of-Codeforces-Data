#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL S(int l, int r) {
	return (LL)(r - l + 1) * (r + l) / 2;
}
const int N = 1000010;
int ans[N], flg[N];
int main() {
	int n; LL k; scanf("%d%lld", &n, &k);
	LL sum = 0;
	for (int i = 1, cur = n; i <= n; i++) {
		while (cur >= 1 && sum + max(cur, i) + S(i + 1, n) > k) cur--;
		if (!cur) {
			puts("-1"); return 0;
		}
		if (cur <= i) {
			int pos = 1;
			for (int j = i; j <= n; j++) {
				while (flg[pos]) pos++;
				ans[j] = pos, pos++;
			}
			break;
		}
		ans[i] = cur, sum += max(i, cur), flg[cur] = 1, cur--;
	}
	LL res = 0;
	for (int i = 1; i <= n; i++) res += max(i, ans[i]);
	cout << res << endl;
	for (int i = 1; i <= n; i++) printf("%d ", i);
	puts("");
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}