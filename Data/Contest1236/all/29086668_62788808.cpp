#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>
#include <functional>
#include <iomanip>

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)
#define FOR_DW(i, beg, end) for (int i = beg; end <= i; i--)

using namespace std;

int64_t kRem = 1000000007;

int64_t pow_rem(int64_t x, int64_t m, int64_t rem)
{
	if (m == 0) {
		return 1;
	}
	if (m == 1) {
		return x;
	}

	if (m & 1) {
		int64_t val = pow_rem(x, m / 2, rem);
		val = val * val;
		val %= rem;
		val *= x;
		val %= rem;
		return val;
	}
	else {
		int64_t val = pow_rem(x, m / 2, rem);
		val = val * val;
		val %= rem;
		return val;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64_t n, m; cin >> n >> m;

	int64_t ans = pow_rem(2, m, kRem);
	ans -= 1;
	if (ans < 0) ans += kRem;

	ans = pow_rem(ans, n, kRem);

	cout << ans << endl;

	return 0;
}