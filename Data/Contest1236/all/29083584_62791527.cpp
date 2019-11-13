#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define pii pair<int, int>
using namespace std;

const int maxn = 1e7 + 5;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const long long inf = 0x3f3f3f3f;

LL qpow(LL x, LL y) {
	LL res = 1;
	while(y) {
		if(y & 1) res = res * x % mod;
		y >>= 1;
		x = x * x % mod;
	}
	return res;
}

int main() {
	LL n, m;
	cin >> n >> m;
	LL ans = qpow(2, m) - 1;
	ans = qpow(ans, n);
	cout << ans << endl;
	return 0;
}