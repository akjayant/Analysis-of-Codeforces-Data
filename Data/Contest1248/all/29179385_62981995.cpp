#include <bits/stdc++.h>

using namespace std;

int n, a[100010];

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long sum1 = 0, sum2 = 0;
	for(int i = 1; i <= n / 2; i++) {
		sum1 += a[i];
	}
	for(int i = n / 2 + 1; i <= n; i++) {
		sum2 += a[i];
	}
	cout << sum1 * sum1 + sum2 * sum2 << endl;
	return 0;
}