// B2. Character Swap (Hard Version)
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	while (T--) {
		int n;
		string s, t;
		cin >> n >> s >> t;
		vector<int> a(26);
		for (int i = 0; i < n; i++) a[s[i] - 'a']++, a[t[i] - 'a']++;
		bool failed = false;
		for (int i = 0; i < a.size(); i++)
			if (a[i] % 2) failed = true;
		if (failed) {
			cout << "No" << endl;
			continue;
		}

		vector<pair<int, int> > ans;

		for (int i = 0; i < n; i++) {
			if (s[i] == t[i]) continue;
			bool found = false;
			for (int j = i + 1; j < n; j++)
				if (s[i] == s[j]) {
					found = true;
					swap(s[j], t[i]);
					ans.push_back(make_pair(j, i));
					break;
				}
			if (found) continue;
			for (int j = i + 1; j < n; j++) {
				if (s[i] == t[j]) {
					swap(s[j], t[j]);
					ans.push_back(make_pair(j, j));
					swap(s[j], t[i]);
					ans.push_back(make_pair(j, i));
					break;
				}
			}
		}

		cout << "Yes" << endl;
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
	}

	return 0;
}
