#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vii;
#define taskname ""
#define all(a) (a).begin(), (a).end()
#define pb push_back

const ll MOD = 1e9 + 7;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vi a(26, 0), b(26, 0);
		for (int i = 0; i < n; ++i) {
			a[s[i] - 'a'] += 1;
			b[t[i] - 'a'] += 1;
		}
		bool ok = 1;
		for (int i = 0; i < 26; ++i) {
			if ((a[i] + b[i]) % 2 != 0) {
				ok = 0;
				break;
			}
		}
		if (!ok) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		vector <pii> ans;
		for (int i = 0; i < n; ++i) {
			if (s[i] == t[i]) {
				continue;
			}
			int k = -1;
			for (int j = i + 1; j < n; ++j) {
				if (s[j] == s[i]) {
					k = j;
					break;
				}
			}
			if (k != -1) {
				ans.emplace_back(k, i);
				swap(s[k], t[i]);
			}
			else {
				for (int j = i + 1; j < n; ++j) {
					if (s[i] == t[j]) {
						k = j;
						break;
					}
				}
				swap(s[i], t[i]);
				ans.emplace_back(i, i);
				swap(s[i], t[k]);
				ans.emplace_back(i, k);
			}
		}
		cout << ans.size() << "\n";
		for (auto& x : ans) {
			cout << x.first + 1 << " " << x.second + 1 << "\n";
		}
	}
	return 0;
}