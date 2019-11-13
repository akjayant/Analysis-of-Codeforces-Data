#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
#include <deque>
#include <sstream>

using namespace std;

#define ll long long
#define ld long double
const int inf = 1000000007;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	for (int tt = 0; tt < q; tt++) {
		string s, t;
		int n;
		cin >> n >> s >> t;
		map<char, int> mp;
		for (int i = 0; i < n; i++) {
			mp[s[i]]++;
			mp[t[i]]++;
		}
		bool f = true;
		for (auto x : mp) {
			if (x.second % 2 != 0) {
				f = false;
				break;
			}
		}
		if (!f) {
			cout << "No\n";
			continue;
		}

		vector<pair<int, int>> ans;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				for (int j = i + 1; j < n; j++) {
					if (s[j] == t[i]) {
						
							ans.push_back({ j, j });
							swap(s[j], t[j]);
							ans.push_back({ i, j });
							swap(s[i], t[j]);
							break;
						
						
					}
					else if (s[i] == t[j]) {
						ans.push_back({ j, j });
						swap(s[j], t[j]);
						ans.push_back({ j, i });
						swap(s[j], t[i]);
						break;
					}
					else if (s[i] == s[j]) {
						
							ans.push_back({ j, i });
							swap(s[j], t[i]);
							break;
	
					}
					else if (t[i] == t[j]) {
						ans.push_back({ i, j });
						swap(s[i], t[j]);
						break;
					}
				}
			}
		}
		cout << "Yes\n";
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
		}

	}
	return 0;
}




