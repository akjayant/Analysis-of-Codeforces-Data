#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

char s[N], t[N];
int c[N];
int main() {
	int q;
	cin >> q;
	while (q--) {
		for (int i = 0; i <= 30; i++)
			c[i] = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> s[i], c[s[i] - 'a']++;
		for (int j = 1; j <= n; j++)
			cin >> t[j], c[t[j] - 'a']++;
		bool bad = 0;
		for (int i = 0; i < 30; i++)
			bad |= c[i] % 2;
		if (bad) {
			cout << "No" << endl;
			continue;
		}
		int cnt = 0;
		vector < pair <int, int> > res;
		for (int i = 1; i <= n; i++) {
			if (t[i] != s[i]) {
				for (int j = i + 1; j <= n; j++) {
					if (t[j] == s[j])
						continue;
					if (t[j] == s[i]) {
						cnt += 2;
						res.push_back({j, j});
						res.push_back({j, i});
						swap(s[j], t[j]);
						swap(s[j], t[i]);
						break;
					}	
					if (s[j] == s[i]) {
						cnt++;
						res.push_back({j, i});
						swap(s[j], t[i]);
						break;
					}
				}
			}
		}
			cout << "Yes" << endl;
			cout << cnt << endl;
			for (int i = 0; i < res.size(); i++)
				cout << res[i].first << " " << res[i].second << endl;

	}	

	return 0;
}

