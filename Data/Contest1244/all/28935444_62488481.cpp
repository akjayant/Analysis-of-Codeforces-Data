#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;
int a[N]; LL sum[N];
int main() {
	int n; LL k; scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1); 
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int l = 0, r = 1e9, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) >> 1; LL res = 1e18;
		for (int i = 1, r = 1; i <= n; i++) {
			LL t = (LL)a[i] * (i - 1) - sum[i - 1];
		 	while (r <= n && a[r] <= a[i] + mid) r++;
		 	t += sum[n] - sum[r - 1] - (LL)(a[i] + mid) * (n - r + 1);
		 	res = min(res, t);
		}
		for (int i = n, l = n; i >= 1; i--) {
			LL t = sum[n] - sum[i] - (LL)a[i] * (n - i);
			while (l >= 1 && a[l] >= a[i] - mid) l--;
			t += (LL)(a[i] - mid) * l - sum[l];
			res = min(res, t);
		}
		if (res <= k) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
}