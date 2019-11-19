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
#include <iomanip>
#include <bitset>
#include <sstream>

#pragma warning(disable : 4996)
using namespace std;

#define all(__array) (__array).begin(), (__array).end()
#define nl '\n'
#define mod(__val, __mod) ((((__val) % (__mod)) + (__mod)) % (__mod))
typedef long long ll;
typedef unsigned long long ull;
typedef double dl;

const ll LINF = numeric_limits<ll>::max();
const int INF = numeric_limits<int>::max();
const double EPS = 1e-8;
const double PI = acos(-1);
random_device rnd;

const int N = (int)1e5 + 10;

inline bool isPrime(ll n) {
	ll d = 2;
	while (d * d <= n && n % d != 0)
		d++;
	return d * d > n;
}

void fac(ll n, vector <ll>& f) {
	for (ll d = 2; d * d <= n; d++) {
		if (n % d == 0) {
			f.push_back(d);
			while (n % d == 0) {
				n /= d;
			}
		}
	}
	if (n != 1) {
		f.push_back(n);
	}
}

void solve() {
	ll n;
	cin >> n;
	if (isPrime(n)) {
		cout << n;
		return;
	}
	vector<ll> f;
	fac(n, f);
	if (f.size() == 1) {
		cout << f.front();
	}
	else {
		cout << 1;
	}
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
	//int t;
	//cin >> t;
	//while(t--)
	solve();
	return 0;
}