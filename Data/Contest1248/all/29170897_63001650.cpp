#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, m, mod = 1e9 + 7;
	cin >> n >> m;
	long long sum = 2, a = 2, b = 2;
	for (int i = 0; i < n - 1; i++) {
		sum = (sum + a) % mod;
		swap(a, b);
		b = (b + a) % mod;
	}
	a = 2;
	b = 2;
	for (int i = 0; i < m - 1; i++) {
		sum = (sum + a) % mod;
		swap(a, b);
		b = (b + a) % mod;
	}
	cout << sum;
}