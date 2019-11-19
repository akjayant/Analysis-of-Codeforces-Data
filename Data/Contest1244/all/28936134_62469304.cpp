#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s;
		cin >> s;
		s = " " + s;
		int maxi = n;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == '1') {
				maxi = max(maxi, 2 * i);
				maxi = max(maxi, 2 * ((int)s.size() - i)); 
			}
		}
		cout << maxi << '\n';
	}
	return 0;
}
