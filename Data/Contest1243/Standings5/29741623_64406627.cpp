#include <bits/stdc++.h>
#define mp make_pair
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
typedef long long LL;
const int maxn = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
int t, n, cnt[26];
string s, r;
typedef pair<int, int> pii;
vector<pii> ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> s >> r;
		for (int i = 0; i < 26; ++i)
			cnt[i] = 0;
		for (int i = 0; i < n; ++i) {
			++cnt[s[i] - 'a'];
			++cnt[r[i] - 'a'];
		}
		ans.clear();
		bool f = false;
		for (int i = 0; i < 26; ++i)
			if (cnt[i] % 2)
				f = true;
		if (f)
			cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i = 0; i < n; ++i) {
				if (s[i] != r[i]) {
					bool find = false;
					for (int j = i + 1; j < n; ++j) {
						if (s[j] == s[i]) {
							ans.pb(mp(j + 1, i + 1));
							swap(r[i], s[j]);
							find = true;
							break;
						}
					}
					if (!find) {
						for (int j = i; j < n; ++j) {
							if (s[i] == r[j]) {
								ans.pb(mp(n, j + 1));
								swap(s[n - 1], r[j]);
								ans.pb(mp(n, i + 1));
								swap(s[n - 1], r[i]);
								break;
							}
						}
					}
				}
			}
			cout << ans.size() << "\n";
			for (int i = 0; i < ans.size(); ++i)
				cout << ans[i].first << " " << ans[i].second << "\n";
		}
	}
}