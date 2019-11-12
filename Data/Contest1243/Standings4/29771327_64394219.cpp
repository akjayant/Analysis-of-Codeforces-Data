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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector<set<int>> p1(26), p2(26);
	for (int i = 0; i < n; i++) {
		p1[s[i] - 'a'].insert(i);
		p2[t[i] - 'a'].insert(i);
	}
	for (int i = 0; i < 26; i++) {
		if ((p1[i].size() + p2[i].size()) % 2) {
			cout << "No" << nl;
			return;
		}
	}
	cout << "Yes" << nl;
	vector<pair<int, int>> swaps;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			p1[s[i] - 'a'].erase(i);
			if (p1[s[i] - 'a'].size()) {
				int p = *(p1[s[i] - 'a'].begin());
				p1[s[p] - 'a'].erase(p);
				p2[t[i] - 'a'].erase(i);
				swap(s[p], t[i]);
				p1[s[p] - 'a'].insert(p);
				p2[t[i] - 'a'].insert(i);
				swaps.push_back({ p + 1, i + 1 });
			}
			else {
				int p = *(p2[s[i] - 'a'].begin());
				int pp = i + 1;
				p1[s[pp] - 'a'].erase(pp);
				p2[t[p] - 'a'].erase(p);
				swap(s[pp], t[p]);
				p1[s[pp] - 'a'].insert(pp);
				p2[t[p] - 'a'].insert(p);
				swaps.push_back({ pp + 1, p + 1 });
				p = i + 1;
				p1[s[p] - 'a'].erase(p);
				p2[t[i] - 'a'].erase(i);
				swap(s[p], t[i]);
				p1[s[p] - 'a'].insert(p);
				p2[t[i] - 'a'].insert(i);
				swaps.push_back({ p + 1, i + 1 });
			}
			p2[t[i] - 'a'].erase(i);
		}
		p1[s[i] - 'a'].erase(i);
		p2[t[i] - 'a'].erase(i);
	}
	cout << swaps.size() << nl;
	for (auto t : swaps) {
		cout << t.first << ' ' << t.second << nl;
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
	cin >> t;
	while (t--)
		solve();
	return 0;
}