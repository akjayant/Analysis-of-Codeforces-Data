#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>

using namespace std;

void solve() {
	int n, m, a0 = 0, a1 = 0, b0 = 0, b1 = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		a1 += (a & 1);
		a0 += !(a & 1);
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		b1 += (a & 1);
		b0 += !(a & 1);
	}
	cout << a0 * 1ll * b0 + a1 * 1ll * b1 << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}