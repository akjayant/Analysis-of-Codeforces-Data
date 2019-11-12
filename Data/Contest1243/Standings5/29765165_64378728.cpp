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

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	//if (s == t) {
	//	cout << "Yes" << nl;
	//	return;
	//}
	vector<int> poses;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			poses.push_back(i);
		}
	}

	if (poses.size() > 2) {
		cout << "No" << nl;
		return;
	}
	for (int i = 0; i < (int)poses.size(); i++) {
		for (int j = 0; j < (int)poses.size(); j++) {
			swap(s[poses[i]], t[poses[j]]);
			if (s == t) {
				cout << "Yes" << nl;
				return;
			}
			swap(s[poses[i]], t[poses[j]]);
		}
	}
	cout << "No" << nl;
	return;
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
	while(t--)
	solve();
	return 0;
}