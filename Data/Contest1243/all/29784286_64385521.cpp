#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

void solve();

signed main () {
    cout.precision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1; 
    cin >> t;
    int tt = t;
    while (t--) { 
        solve();
    }
    return 0;
}
string s, t;
void solve() {
	int n;
	cin >> n;
	cin >> s >> t;
	int cnt = 0;
	for (int i = 0; i < (int) s.size(); ++i) 
		if (s[i] != t[i])
			++cnt;
	if (cnt == 0) {
		cout << "Yes\n";
		return;
	}
	if (cnt == 1) {
		cout << "No\n";
		return;
	}
	if (cnt >= 3) {
		cout << "No\n";
		return;
	}
	set<pair<char, char>> lol;
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i])
			lol.insert({s[i], t[i]});
	}
	if ((int) lol.size() == 1) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
}     