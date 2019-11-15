#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <assert.h>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <random>
#include <cmath>

//#define ll long long
#define ld long double
//#define mp make_pair
#define pb push_back
#define eb emplace_back
#define int long long
using namespace std;

const int INF = 2e9;
const int MOD = 1e9 + 7;
const int MB = 30;

void go() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector<int> a;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != t[i]) {
			a.pb(i);
		}
	}


	vector<pair<int, int>> ans;
	vector<bool> used(a.size());
	for (int i = 0; i < a.size(); i++) {
		if (s[a[i]] == t[a[i]]) {
			used[i] = true;
			continue;
		}
		for (int j = i + 1; j < a.size(); j++) {
			if (used[j]) continue;
			int x = a[i];
			int y = a[j];
			if (s[x] == s[y]) {
				ans.pb({ y + 1, x + 1 });
				swap(s[y], t[x]);
				used[i] = true;
				break;
			}
		}
		if (!used[i]) {
			for (int j = i + 1; j < a.size(); j++) {
				if (used[j]) continue;
				int x = a[i];
				int y = a[j];
				if (s[x] == t[y]) {
					ans.pb({ y + 1, y + 1 });
					swap(s[y], t[y]);
					ans.pb({ y + 1, x + 1 });
					swap(s[y], t[x]);
					used[i] = true;
					break;
				}
			}
		}
	}

	bool good = true;
	for (int i = 0; i < a.size(); i++) {
		if (!used[i]) {
			good = false;
		}
	}

	if (good) {
		cout << "Yes\n";
		cout << ans.size() << '\n';
		for (auto& p : ans) {
			cout << p.first << " " << p.second << '\n';
		}
	}
	else {
		cout << "No\n";
	}
}

void solve() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		go();
	}
}

signed main() {
	/*
	freopen("cyclic.in", "r", stdin);
	freopen("cyclic.out", "w", stdout);
	*/
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(12);
	solve();
}
