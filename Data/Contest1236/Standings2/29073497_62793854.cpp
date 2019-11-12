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
	ll n;
	scanf("%lld", &n);
	vector<vector<ll>> a(n);
	ll id = 0;
	for (ll i = 1; i <= n * n; i++) {
		a[id].push_back(i);
		ll sz = a[id].size();
		if (sz & 1) {
			id++;
			if (id == n) {
				id--;
			}
		}
		else {
			id--;
			if (id == -1) id++;
		}
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			printf("%lld", a[i][j]);
			if (j == n - 1) {
				printf("\n");
			}
			else {
				printf(" ");
			}
		}
	}
	return 0;
}