#include <bits/stdc++.h>

using namespace std;

int v[2207];
 
int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k; cin >> k;
	while (k--) {
		int n; string s, t;
    	cin >> n >> s >> t;
    	vector <int> ps;
    	for (int i = 0; i < n; i++) {
    		if (s[i] != t[i]) {
    			v[s[i] - '0']++;
    			v[t[i] - '0']++;
    			ps.push_back(i);
			}
		}
		bool f = false;
		for (int i = 0; i < 30; i++) {
			if (v[i] & 1) {
				f = true;
				cout << "No\n";
				break;
			}
		}
		if (f) continue;
		int m = (int)ps.size();
		vector<pair<int, int> > ans;
		bool ff = false;
		for (int i = 0; i < m; i++) {
			if (s[ps[i]] == t[ps[i]]) continue;
			f = false;
			for (int j = i + 1; j < m; j++) {
				if (t[ps[i]] == t[ps[j]]) {
					ans.push_back({ps[i], ps[j]});
					swap(s[ps[i]], t[ps[j]]);
					f = true;
					break;
				}
			}
			if (f) continue;
			for (int j = i + 1; j < m; j++) {
				if (t[ps[i]] == s[ps[j]]) {
					ans.push_back({ps[j], ps[j]});
					swap(s[ps[j]], t[ps[j]]);
					ans.push_back({ps[i], ps[j]});
					swap(s[ps[i]], t[ps[j]]);
					f = true;
					break;
				}
			}
			if (!f) {
				ff = true;
				cout << "No\n";
				break;
			}
		}
		if (ff) continue;
		cout << "Yes\n" << ans.size() << '\n';
		for (auto x : ans) cout << x.first + 1 << ' ' << x.second + 1 << '\n';
	}
    return 0;
}