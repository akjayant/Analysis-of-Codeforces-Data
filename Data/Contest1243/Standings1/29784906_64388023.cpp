#include <bits/stdc++.h>

#define boost ios_base::sync_with_stdio(false), cin.tie(NULL);

using namespace std;
const int N = 1e6 + 55;
const int mod = 1e9 + 7;
const long long INF = 1e18 + 12;
const int inf = 1e9;

int a[N];

int main () {
	boost;
	int t;
	cin >> t;
	while (t--) {
		int n; string s, t;
		cin >> n >> s >> t;
		vector <int> pos;
		int ok = 0;
		vector <int> cnt (44);
		for (int i = 0 ; i < n ; ++ i) {
			if (s[i] != t[i]) pos.push_back (i);
			cnt[s[i] - 'a']++;
			if (cnt[s[i] - 'a'] > 1) ok = 1;
		}
		if (pos.size() == 0) {
			if (ok) cout << "Yes";
			else cout << "No";
			cout << "\n";
			continue;
		}
		if (pos.size() != 2) {
			cout << "No\n";
			continue;
		}
		if (s[pos[0]] == s[pos[1]] && t[pos[0]] == t[pos[1]]) cout << "Yes";
		else cout << "No";
		cout << "\n";
	}
}