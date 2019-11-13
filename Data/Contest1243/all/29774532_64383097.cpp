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
		vi kek;
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i]) {
				kek.push_back(i);
			}
		}
		if (kek.size() != 2) {
			cout << "No\n";
			continue;
		}
		if (s[kek[0]] == s[kek[1]] && t[kek[0]] == t[kek[1]]) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	return 0;
}