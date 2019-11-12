
// ~/Wiley/Atypon/RedLink/Developers/Corvus
// ~/sudo apt-get verdict Accpeted

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <functional>
#include <assert.h>
#include <complex>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 200005, M = 1005;
const ll MOD = 1e9 + 7;
const double eps = 1e-9;
const double PI = acos(-1.0);

int n, m;

int fast_pow(int b, int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return b;
	if (n % 2 == 1)
		return (1ll * b * fast_pow(b, n - 1)) % MOD;
	int r = fast_pow(b, n/2);
	return (1ll * r * r) % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	int ans = fast_pow(2, m);
	ans = (ans - 1 + MOD) % MOD;
	ans = fast_pow(ans, n);
	cout << ans << endl;
	return 0;
}