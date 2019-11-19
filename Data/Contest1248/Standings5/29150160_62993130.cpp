// *** creator : cfmasterr *** //
#include <bits/stdc++.h>
#define int long long

using namespace std;

int md = (int) 1e9 + 7;

int fib(int n) {
	if (n == 1) return 2;
	if (n == 2) return 4;
	int x1 = 2, x2 = 4;
	for (int i = 3; i <= n; i++) {
		int y = x2;
		x2 += x1;
		x1 = y;
		x2 %= md;
	}
	return x2;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  cout << ((fib(n) + fib(m)) - 2) % md;
  return 0;
}

