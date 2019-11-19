#include <bits/stdc++.h>
using namespace std;

int main() {
	int d[10][10], to[100];
	for (int i = 0; i != 10; ++i) for (int j = 0; j != 10; ++j) {
		int h;
		cin >> h;
		d[i][j] = i * 10 + (i & 1 ? 9 - j : j);
		to[d[i][j]] = d[i - h][j];
	}
	double exp[100];
	fill_n(exp, 100, 0.0F);
	for (int i = 1; i != 6; ++i) {
		for (int j = 0; j != i; ++j) exp[i] += exp[j];
		exp[i] = (exp[i] + 6) / i;
	}
	for (int i = 6; i != 100; ++i) {
		for (int j = 1; j <= 6; ++j) exp[i] += min(exp[i - j], exp[to[i - j]]);
		exp[i] = exp[i] / 6 + 1;
	}
	cout << fixed << setprecision(7) << exp[99] << endl;
}
