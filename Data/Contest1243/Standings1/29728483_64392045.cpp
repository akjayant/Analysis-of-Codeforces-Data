#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define emp emplace
typedef long long ll;
typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int k; cin >> k;

	while (k--) {
		int n; cin >> n;
		string s, t; cin >> s >> t;
		vector<ii> ans;

		int res = 1;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				bool ok = 0;
				for (int j = i+1; j < n; j++) {
					if (s[j] == s[i]) {
						ans.eb(j, i);
						swap(s[j], t[i]);
						ok = 1;
						break;
					}
				}

				if (!ok) {
					for (int j = i+1; j < n; j++) {
						if (s[i] == t[j]) {
							ans.eb(n-1, j);
							swap(s[n-1], t[j]);
							ans.eb(n-1, i);
							swap(s[n-1], t[i]);
							ok = 1;
							break;
						}
					}
				}

				if (!ok) res = 0;
			}
		}
		if (res) {
			cout << "Yes" << endl;
			cout << ans.size() << endl;
			for (auto x : ans) cout << x.fi+1 << " " << x.se+1 << endl;
		} else {
			cout << "No" << endl;
		}
	}


	return 0;
}
