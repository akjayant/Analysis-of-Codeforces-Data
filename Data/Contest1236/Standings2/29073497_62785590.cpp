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


int main()
{
	ll t;
	scanf("%lld", &t);
	for (ll loop = 0; loop < t; loop++) {
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		ll res = 0;
		ll t = 0;
		t += min(b, c / 2);
		b -= t;
		res += t * 3;
		res += min(a, b / 2) * 3;
		printf("%lld\n", res);
	}
	return 0;
}