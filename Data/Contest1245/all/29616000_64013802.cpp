#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<char, int> cnt;
		cin >> cnt['R'] >> cnt['P'] >> cnt['S'];
		map<char, char> mp = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
		string s, ans(n, '?');
		cin >> s;
		int score = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (cnt[mp[s[i]]]) {
				cnt[mp[s[i]]]--;
				ans[i] = mp[s[i]];
				score++;
			}
		}
		for (int i = 0; i < s.size(); ++i) {
			if (ans[i] != '?') {
				continue;
			}
			for (auto& it: cnt) {
				if (it.second) {
					ans[i] = it.first;
					it.second--;
					break;
				}
			}
		}
		if (score >= (n + 1) / 2) {
			cout << "YES" << endl << ans << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}