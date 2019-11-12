#include <iostream>
#include <string>
#include  <map>
#include <vector>
using namespace std;

int main()
{
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		string s, t, s1, t1;
		cin >> s >> t;
		map<char, int> cnt;
		vector<int> pos;
		for (int i = 0; i < n; ++i) 
			if (s[i] != t[i]) {
				s1 += s[i];
				t1 += t[i];
				pos.push_back(i + 1);
				cnt[s[i]]++;
				cnt[t[i]]++;
			}

		bool flag = false;
		for (auto i : cnt)
			if (i.second % 2 == 1)
				flag = true;

		if (flag) {
			cout << "No" << endl;
			continue;
		}

		cout << "Yes" << endl;
		vector<pair<int, int>> ans;
		vector<int> used(s1.size(), 0);

		for (int i = 0; i < s1.size() - 1; ++i) 
			if (!used[i]) {
				char ch = s1[i];
				for (int j = i + 1; j < n; ++j) 
					if (!used[j] && s1[j] == ch) {
						swap(t1[i], s1[j]);
						used[i] = 1;
						ans.push_back({ pos[j], pos[i]});
						if (s1[j] == t1[j])
							used[j] = 1;
						break;
					}
					else if (!used[j] && t1[j] == ch) {
						swap(s1[j], t1[j]);
						ans.push_back({pos[j], pos[j]});
						swap(t1[i], s1[j]);
						used[i] = 1;
						ans.push_back({ pos[j], pos[i]});
						if (s1[j] == t1[j])
							used[j] = 1;
						break;
					}
			}

		cout << ans.size() << endl;
		for (auto i : ans)
			cout << i.first << ' ' << i.second << endl;
	}
	return 0;
}