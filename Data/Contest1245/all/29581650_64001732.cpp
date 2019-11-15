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
	int n;
	cin >> n;
	int r, p, s;
	cin >> r >> p >> s;
	int wins = 0;
	string t;
	cin >> t;
	string ans;
	for (auto& i : t) {
		if (i == 'R' && p > 0) {
			wins++;
			p--;
			ans += 'P';
		}
		else if (i == 'P' && s > 0) {
			wins++;
			s--;
			ans += 'S';
		}
		else if (i == 'S' && r > 0) {
			wins++;
			r--;
			ans += 'R';
		}
		else {
			ans += 'Q';
		}
	}
	
	if (wins >= (n + 1) / 2) {
		cout << "YES" << nl;
		for (auto& i : ans) {
			if (i != 'Q') {
				cout << i;
			}
			else {
				if (r > 0) {
					r--;
					cout << 'R';
				}
				else if (s > 0) {
					s--;
					cout << 'S';
				}
				else if (p > 0) {
					p--;
					cout << 'P';
				}
			}
		}
		cout << nl;
	}
	else {
		cout << "NO" << nl;
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
	int t;
	cin >> t;
	while (t--)
	solve();
	return 0;
}