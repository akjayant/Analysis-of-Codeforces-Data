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
	map<char, set<int>> mps, mpt;
	for (int i = 0; i < n; i++) {
		mps[s[i]].insert(i);
		mpt[t[i]].insert(i);
	}

	for (char c = 'a'; c <= 'z'; c++) {
		if ((mps[c].size() + mpt[c].size()) & 1) {
			cout << "No" << nl;
			return;
		}
	}

	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		if (s[i] == t[i]) {
			continue;
		}
		auto tmp = mps[s[i]].upper_bound(i);
		if (tmp != mps[s[i]].end()) {
			int pos = *tmp;
			ans.push_back({ pos, i });
			mps[s[pos]].erase(pos);
			mpt[t[i]].erase(i);
			swap(s[pos], t[i]);
			mpt[t[i]].insert(i);
			mps[s[pos]].insert(pos);
		}
		else {
			tmp = mpt[s[i]].upper_bound(i);
			int pos = *tmp;
			ans.push_back({ i + 1, pos });
			mps[s[i + 1]].erase(i + 1);
			mpt[t[pos]].erase(pos);
			swap(s[i + 1], t[pos]);
			mpt[t[pos]].insert(pos);
			mps[s[i + 1]].insert(i + 1);
			i--;
		}
	}

	cout << "Yes" << nl << ans.size() << nl;
	for (auto& i : ans) {
		cout << i.first + 1 << " " << i.second + 1 << nl;
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
	while(t--)
	solve();
	return 0;
}