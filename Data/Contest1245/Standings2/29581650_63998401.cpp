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

#define ft first
#define sd second
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

inline int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

inline void solve() {
	int a, b;
	cin >> a >> b;
	cout << (gcd(a, b) == 1 ?  "Finite" : "Infinite") << nl;
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
	int t;
	cin >> t;
	while (t--)
	solve();
	return 0;
}