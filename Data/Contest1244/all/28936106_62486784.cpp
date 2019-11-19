#include <iostream>
#include <queue>
#include <algorithm>
#include <random>
#include <vector>
#include <assert.h>
#include <set>
#include <unordered_set>
#include <numeric>
#include <map>
#include <string>
#include <cstdlib>
#include <cstdio>

#pragma warning(disable : 4996)
using namespace std;

#define ft first
#define sd second
#define all(__array) (__array).begin(), (__array).end()
#define nl '\n'

typedef long long ll;
typedef double dl;

const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const dl EPS = 1e-8;
const dl PI = acos(-1);
random_device rnd;

const int N = (int)1e5 + 10;
const int M = 17;
const int K = 320;

const int MOD = (int)1e9 + 7;

inline void solve() {
	int n;
	ll k;
	cin >> n >> k;
	map<ll, int> mp;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		mp[val]++;
	}
	
	while (k && mp.size() > 1) {
		auto begin = mp.begin();
		auto last = prev(mp.end());

		int cntBeg = begin->second;
		int cntLast = last->second;

		if (cntBeg < cntLast) {
			ll dif = next(begin)->first - begin->first;
			if (dif * 1LL * cntBeg <= k) {
				next(begin)->second += cntBeg;
				k -= dif * 1LL * cntBeg;
				mp.erase(begin);
			}
			else {
				ll newVal = begin->first + k / cntBeg;
				k = 0;
				mp.erase(begin);
				mp.insert({ newVal, cntBeg });
			}
		}
		else {
			ll dif = last->first - prev(last)->first;
			if (dif * 1LL * cntLast <= k) {
				prev(last)->second += cntLast;
				k -= dif * 1LL * cntLast;
				mp.erase(last);
			}
			else {
				ll newVal = last->first - k / cntLast;
				k = 0;
				mp.erase(last);
				mp.insert({ newVal, cntLast });
			}
		}
	}


	cout << prev(mp.end())->first - mp.begin()->first << nl;
}

inline void IO() {
#ifdef _SEVA
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}


int main() {
	IO();
	solve();
	return 0;
}
