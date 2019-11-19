#include <bits/stdc++.h>

using namespace std;

int a[100010], n, b[100010], c[100010], N;
long long k;

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = 0x7fffffff;
	sort(a + 1, a + n + 1);
	int N = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] != a[i - 1]) b[++N] = a[i], c[N] = 1;
	    else c[N]++;
	}
	int l = 1, r = N;
	while(l < r) {
		int sel = -1, qwq = 0x7fffffff;
		if(qwq > c[l] && k >= c[l]) {
			qwq = c[l];
			sel = 1;
		}
		if(qwq > c[r] && k >= c[r]) {
			qwq = c[r];
			sel = 2;
		}
		if(sel == -1) {
			break;
		}
		if(sel == 1) {
			int qaq = (int)min(1ll * b[l + 1] - b[l], k / c[l]);
			if(qaq == b[l + 1] - b[l]) {
				c[l + 1] += c[l];
				k -= 1LL * qaq * c[l];
				l++;
			} else {
				b[l] += qaq;
				k -= 1LL * qaq * c[l];
			}
			// cout << "left " << l << " " << k << endl;;
		} else {
			int qaq = (int)min(1ll * b[r] - b[r - 1], k / c[r]);
			if(qaq == b[r] - b[r - 1]) {
				c[r - 1] += c[r];
				k -= 1LL * qaq * c[r];
				r--;
			} else {
				b[r] -= qaq;
				k -= 1LL * qaq * c[r];
			}
			// cout << "right " << r << " " << k << endl;;
		}
	}
	cout << b[r] - b[l];
	return 0;
}