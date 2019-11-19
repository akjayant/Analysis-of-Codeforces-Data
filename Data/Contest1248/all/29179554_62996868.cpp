#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

int n, m;
long long f[1000001][2][2];

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
	n = read<int>(), m = read<int>();
	f[1][0][0] = f[1][1][0] = 1;
	f[2][0][0] = f[2][0][1] = f[2][1][0] = f[2][1][1] = 1;
	for (int i = 3; i <= 1000000; i++) {
		f[i][0][0] = f[i - 1][0][1];
		f[i][0][1] = (f[i - 1][1][0] + f[i - 1][1][1]) % MOD;
		f[i][1][0] = (f[i - 1][0][1] + f[i - 1][0][0]) % MOD;
		f[i][1][1] = f[i - 1][1][0];
	}
	cout << ((f[m][0][0] + f[m][0][1] + f[m][1][0] + f[m][1][1] - 2) % MOD
	            + f[n][0][0] + f[n][0][1] + f[n][1][0] + f[n][1][1]) % MOD
	     << '\n';
	return 0;
}
