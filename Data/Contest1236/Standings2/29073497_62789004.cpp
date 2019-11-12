#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <bitset>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long MAX = 510000;
const long long INF = 1LL << 60;
const long long MOD = 1000000007LL;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


ll power(ll x, ll n, ll p = 1000000007) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 0) {
		return power(x * x % p, n / 2, p) % p;
	}
	else {
		return x * power(x, n - 1, p) % p;
	}
}

int main()
{

	ll n, m;
	scanf("%lld %lld", &n, &m);
	ll a, b;
	a = (power(2, m, MOD) - 1) % MOD;
	if (a < 0) a += MOD;
	ll res = power(a, n, MOD);
	printf("%lld\n", res);
	return 0;
}