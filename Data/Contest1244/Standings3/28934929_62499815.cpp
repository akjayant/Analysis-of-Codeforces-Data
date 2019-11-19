#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>
#include <bitset>
#include <unordered_map>
#include <stack>
#include <memory.h>
#include <list>
#include <numeric>
#include <functional>
#include <complex>
#include <cassert>
#include <regex>
#include <random>

#define ll long long
#define ld long double
#define ull unsigned ll
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pii pair<int,int> 
#define pll pair<ll, ll> 
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vector<int>>
#define forn(it,from,to) for(ll (it)=from; (it)<to; (it)++)
ld pi = acos(-1.0);
using namespace std;


int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("hotel.in", "r", stdin);
	//freopen("hotel.out", "w", stdout);
	//reopen("input.txt", "r", stdin);
	//reopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vll a(n);
	forn(i, 0, n) cin >> a[i];
	sort(all(a));
	vll chs;
	chs.push_back(0);
	forn(i, 0, n) {
		chs.push_back(chs.back() + a[i]);
	}
	ll l = 0, r = a.back() - a[0];
	while (l < r) {
		ll m = (l + r) / 2;
		bool ok = false;
		ll sum = 1e18;
		forn(i, 0, n) {

			ll l1 = a[i], r1 = a[i] + m;
			ll curs = i * l1 - chs[i];
			ll p = upper_bound(all(a), r1) - a.begin();
			if (p != n) {
				curs += chs[n] - chs[p] - (n - p) * r1;
			}
			sum = min(sum, curs);

			ll l2 = a[i] - m, r2 = a[i];
			curs = chs[n] - chs[i + 1] - (n - i - 1) * r2;
			p = lower_bound(all(a), l2) - a.begin() - 1;
			if (p >= 0) {
				curs += l2 * (p + 1) - chs[p + 1];
			}
			sum = min(sum, curs);
		}
		if (sum > k) {
			l = m + 1;
		}
		else r = m;
	}
	cout << l;
	return 0;
}