#include  <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	// freopen("in", "r", stdin);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; cin >> s;
		s = "~" + s;
		int mn = 1e9, mx = 0;
		for(int i = 1; i <= n; i++) {
			if(s[i] == '1') {
				mn = min(mn, i);
				mx = max(mx, i);
			}
		}
		int ans = n;
		if(mx) ans++;
		ans = max(ans, 2 * mx);
		ans = max(ans, (n - mn + 1) * 2);
		cout << ans << endl;
	}
	return 0;
}