#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
string s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> s;
		int ans = n;
		for(int i = 0; i < n; i++) {
			if(s[i] == '1') ans = max({ans, 2 * (i + 1), 2 * (n - i)});
		} cout << ans << "\n";
	}
	return 0;
}