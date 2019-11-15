#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define X first
#define Y second
#define sz(v) (int)v.size()

void solve();

main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ONPC
	freopen("in.txt", "r", stdin);
#endif
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}



void solve() {
	int n;
	string s, t;
	cin >> n;
	cin >> s >> t;
	vector<int> v;
	for (int i = 0; i < sz(s); ++i) {
		if (s[i] != t[i]) {
			v.pb(i);
		}
	}
	if (sz(v) != 2) {
		cout << "No\n";
		return;
	}
	if (s[v[0]] != s[v[1]] || t[v[0]] != t[v[1]]) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
}