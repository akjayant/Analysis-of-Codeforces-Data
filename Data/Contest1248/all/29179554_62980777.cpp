#include <bits/stdc++.h>

using namespace std;

int ntest;
int n, m;
int cnt1, cnt2, cnt3, cnt4;

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
	ntest = read<int>();
 
	while (ntest--) {
		cnt1 = cnt2 = cnt3 = cnt4 = 0;

		n = read<int>();
		for (int i = 1; i <= n; i++) {
			if (read<int>() & 1) {
				cnt1++;
			} else {
				cnt2++;
			}
		}

		m = read<int>();
		for (int i = 1; i <= m; i++) {
			if (read<int>() & 1) {
				cnt3++;
			} else {
				cnt4++;
			}
		}

		printf("%I64d\n", 1LL * cnt1 * cnt3 + 1LL * cnt2 * cnt4);
	}

	return 0;
}
