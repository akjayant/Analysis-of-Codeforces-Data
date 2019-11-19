#include <bits/stdc++.h>
#define int long long

using namespace std;

long long n, k;
int a[100005];

long long calc(int pos, int x) {
	long long res = 0;
	int l = pos - (x - 1) / 2, r = pos + x / 2;
	for (int i = 1; i <= n; ++i)
		if (a[i] < l) res += l - a[i];
		else if (a[i] > r) res += a[i] - r;
	return res;
}

bool check(int x) {
	int l = x / 2, r = 1e9, L, R, ans;
	while (l < r) {
		L = l + (r - l) / 3;
		R = r - (r - l) / 3;
		if (calc(L, x + 1) < calc(R, x + 1)) r = R - 1;
		else l = L + 1;
	}
	return calc(l, x + 1) <= k;
}

signed main() {
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	int l = 0, r = 1e9, mid, ans;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}

	cout << ans << endl;
	return 0;
}
