//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

int q;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		int a[26] = {};
		for (auto i : s)
			a[i - 'a']++;
		for (auto i : t)
			a[i - 'a']++;
		bool flag = true;
		for (int i = 0; i < 26; i++)
		       if (a[i] % 2)
		       flag = false;
		if (!flag) {
			cout << "No" << endl;
			continue;
		}
		vector<pii> ans;
		for (int i = 0; i < n; i++) {
			if (s[i] == t[i])
				continue;
			int j = i + 1;
			while (t[j] != t[i] && j < n)
				j++;
			if (j == n) {
				int p;
				for (p = i + 1; p < n; p++)
					if (s[p] == t[i])
						break;
				swap(s[p], t[n - 1]);
				ans.pb({p, n - 1});
				j--;
			}
			swap(t[j], s[i]);
			ans.pb({i, j});
		}
		cout << "Yes" << endl;
		cout << ans.size() << endl;
		for (auto i : ans)
			cout << i.ff + 1 << " " << i.ss + 1 << endl;
	}
	return 0;
}
