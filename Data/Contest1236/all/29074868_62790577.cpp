#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <map>
#define int long long
#define double long double
using namespace std;
int p = 1000000007;

int fast(int n, int s) {
	if (s == 0)
		return 1;
	int res = fast(n, s / 2);
	res = (res * res) % p;
	if (s % 2 == 1)
		res *= n;
	return res % p;
}

signed main() {
	int n, m;
	cin >> n >> m;
	cout << fast(fast(2, m) - 1, n);
}