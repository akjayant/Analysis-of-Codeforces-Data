#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define X first
#define Y second
#define sz(v) (int)v.size()

void solve();

main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ONPC
	freopen("in.txt", "r", stdin);
#endif
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}



void solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	vector<int> cnt(26, 0);
	for (auto d : s) cnt[d - 'a']++;
	for (auto d : t) cnt[d - 'a']++;
	for (auto d : cnt) {
		if (d & 1) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
	vector<pair<int, int>> v;
	for (int i = 0; i < sz(s); ++i) {
		if (s[i] == t[i]) continue;
//		cout << s << '\n' << t << '\n' << '\n';
		int j = i + 1;
		for (; j < n && t[i] != t[j]; ++j) {}
		if (j != n) {
//			cerr << "B " << i << ' ' << j << '\n';
//			cout << i + 1 << ' ' << j + 1 << '\n';
			v.pb({i + 1, j + 1});
			swap(s[i], t[j]);
			continue;
		}
//		cerr << "A " << i << ' ' << j << '\n';
		j = i + 1;
		for (; j < n && t[i] != s[j]; ++j) {}
		assert(j != n);
//		cout << j + 1 << ' ' << i + 2 << '\n';
		v.pb({j + 1, i + 2});
		swap(s[j], t[i + 1]);
//		cout << i + 1 << ' ' << i + 2 << '\n';
		v.pb({i + 1, i + 2});
		swap(s[i], t[i + 1]);
	}
	cout << sz(v) << '\n';
	for (auto d : v) cout << d.X << ' ' << d.Y << '\n';
}