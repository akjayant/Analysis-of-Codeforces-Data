#include <bits/stdc++.h>
using namespace std;

int tc, n, cnt[26];
string a, b;
vector<pair<int,int>> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> a >> b;

		memset(cnt, 0, sizeof(cnt));
		ans.clear();

		for (int i = 0; i < n; i++) {
			cnt[a[i] - 'a']++;
			cnt[b[i] - 'a']++;
		}

		bool ok = true;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] & 1) {
				ok = false;
			}
		}

		if (!ok) {
			cout << "No\n";
			continue;
		}

		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				bool ada = false;
				for (int j = i + 1; j < n; j++) {
					if (a[i] == a[j]) {
						swap(a[j], b[i]);
						ans.push_back(make_pair(j, i));
						ada = true;
						break;
					}
				}

				if (ada) {
					continue;
				}

				for (int j = i + 1; j < n; j++) {
					if (a[i] == b[j]) {
						swap(a[j], b[j]);
						ans.push_back(make_pair(j, j));

						swap(a[j], b[i]);
						ans.push_back(make_pair(j, i));
						break;
					}
				}
			}
		}

		cout << "Yes\n" << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
		}
	}

	return 0;
}