#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

void solve();

signed main () {
    cout.precision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1; 
    cin >> t;
    int tt = t;
    while (t--) { 
        solve();
    }
    return 0;
}
void solve() {
	int cnt[26] = {0};
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < n; ++i) {
		cnt[s[i] - 'a']++;
		cnt[t[i] - 'a']++;
	}
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] % 2) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
	vector<pair<int, int>> ops;
	for (int i = 0; i < n; ++i) {
		if (s[i] == t[i])
			continue;
		bool ok = false;
		for (int j = i + 1; j < n; ++j) {
			if (s[j] == s[i]) {
				ok = true;
				ops.push_back({j, i});
				swap(s[j], t[i]);
				break;
			}
		}
		if (ok)
			continue;
		for (int j = i + 1; j < n; ++j) {
			if (t[j] == s[i]) {
				ok = true;
				ops.push_back({j, j});
				swap(s[j], t[j]);
				ops.push_back({j, i});
				swap(s[j], t[i]);
				break;
			}
		}
		assert(ok);
	}
	cout << (int) ops.size() << '\n';
	for (auto i : ops) {
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';
	}
	assert(s == t);
}     