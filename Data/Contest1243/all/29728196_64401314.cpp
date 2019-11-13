#include <bits/stdc++.h>
//#include <ext/numeric>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define oo 0x3f3f3f3f
#define OO 0x3f3f3f3f3f3f3f3f
#define popcount(n) __builtin_popcount(n)
#define popcountll(n) __builtin_popcountll(n)
#define long long long

using namespace std;
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const double PI = acos(-1.0), EPS = 1e-9;

int main() {

	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vector<int> cnt(26, 0);
		for (int i = 0; i < n; ++i) {
			cnt[s[i] - 'a']++;
			cnt[t[i] - 'a']++;
		}
		bool f = true;
		for (int i = 0; i < 26; ++i)
			f &= (cnt[i] % 2 == 0);
		if (!f) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		vector<pair<int, int>> ans;
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i]) {
				for (int j = i + 1; j < n; ++j) {
					if (s[i] == t[j]) {
						ans.push_back( { j, j });
						swap(s[j], t[j]);
					}
					if (s[j] == s[i]) {
						ans.push_back( { j, i });
						swap(t[i], s[j]);
						break;
					}
				}
			}
		}
		cout << ans.size() << '\n';
		for (auto p : ans)
			cout << p.first + 1 << ' ' << p.second + 1 << '\n';
	}

	return 0;
}
