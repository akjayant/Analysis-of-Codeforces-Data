#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n;
int a[100001];
ll sum1 = 0, sum2 = 0;

template <typename T>
inline T read() {
	T x = 0;
	T multiplier = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			multiplier = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch & 15);
		ch = getchar();
	}
	return x * multiplier;
}

int main() {
	n = read<int>();
	for (int i = 1; i <= n; i++) {
		a[i] = read<int>();
	}
	
	sort(a + 1, a + n + 1);

	for (int i = (n >> 1) + 1; i <= n; i++) {
		sum1 += a[i];
		if (i - (n >> 1) <= (n >> 1)) {
			sum2 += a[i - (n >> 1)];
		}
	}

	cout << sum1 * sum1 + sum2 * sum2 << '\n';

	return 0;
}
