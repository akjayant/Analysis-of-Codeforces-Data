#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
int a[100005];

bool check(int len) {
	len++;
	int left = 0, right = 0, nle = 0, nri = 0;
	int l = 0;
	for (int i = 1; i <= n / 2; i++) {
		if (a[n + 1 - i] - a[i] > len) {
			left += a[i];
			nle++;
			right += a[n + 1 - i];
			nri++;
		} else if (a[n + 1 - i] - a[i] == len) {
			left += a[i];
			nle++;
			l = a[i] + 1;
		}
	}
	int r = l + len - 1;
	int ans = nle * l - left  + right - nri * r;
	if (ans > k) return false;
	return true; 
}

main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int l = 0, r = 1e9;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		} else l = mid;
	}
	for (int i = l; i <= r; i++) {
		if (check(i)) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
