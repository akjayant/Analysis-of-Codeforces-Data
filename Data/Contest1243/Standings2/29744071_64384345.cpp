#include <bits/stdc++.h>

using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k; cin >> k;
	while (k--) {
		int n; string s, t; 
		cin >> n >> s >> t;
		vector<bool> v(n);
		for (int i = 0; i < n; i++) if (s[i] == t[i]) v[i] = true;
		int cnt = 0;
		for (int i = 0; i < n; i++) cnt += !v[i];
		if (!cnt) cout << "Yes\n";
		else if (cnt != 2) cout << "No\n";
		else {
			vector<int> x;
			for (int i = 0; i < n; i++) if (v[i] == 0) x.push_back(i);
			swap(s[x[0]], t[x[1]]);
			cout << (s == t ? "Yes" : "No") << '\n';
		}
	}
    return 0;
}