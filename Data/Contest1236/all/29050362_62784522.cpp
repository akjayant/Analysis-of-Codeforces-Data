
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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	int tc, a, b, c;
	cin >> tc;
	while (tc--) {
		cin >> a >> b >> c;
		int ans = min(c / 2, b);
		b -= ans;
		ans *= 3;
		ans += 3 * min(b / 2, a);
		cout << ans << endl;
	}
	return 0;
}