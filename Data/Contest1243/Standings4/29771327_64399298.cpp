#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <iomanip>
#include <random>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <sstream>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define z(x) fixed << setprecision(x)
#define mp make_pair
#define sqr(x) ((x)*(x))
#define nl '\n'
#define eb emplace_back
#define elif else if
#define ft first
#define sd second
#define dbg(a) cout << (#a) << " " << a << nl;
#pragma comment(linker, "/STACK:16777216")

typedef long long ll;
typedef unsigned long long ull;
typedef short int sht;
typedef unsigned short int usht;
mt19937 rnd(22358);

inline void solve() {
	ll n;
	cin >> n;
	int del = 0;
	for (ll i = 2; i <= n; i++) {
		if (i*i > n) {
			break;
		}
		if (n%i == 0) {
			while (n%i == 0) {
				n /= i;
			}
			del = i;
			if (n > 1) {
				cout << 1;
				return;
			}
			break;
		}
	}
	if (del) {
		cout << del;
	}
	else {
		cout << n;
	}
}

inline void IO() {
#ifdef _DIVAN	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main() {
	IO();
	int t;
	t = 1;
	while (t--)
		solve();
	return 0;
}