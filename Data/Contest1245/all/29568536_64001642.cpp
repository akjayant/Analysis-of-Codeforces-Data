#include <bits/stdc++.h>

using namespace std;

int t, n, a, b, c, x, y, z;
string s;

int main(){
	cin >> t;
	while (t--) {
		cin >> n >> a >> b >> c >> s;
		x = 0, y = 0, z = 0;
		for (int i = 0; i < n; ++i)
			if (s[i] == 'P')
				y++;
			else if (s[i] == 'R')
				x++;
			else
				z++;
		if ((min(a, z) + min(b, x) + min(c, y)) * 2 < n) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		string ans(n, '@');
		for (int i = 0; i < n; ++i)
			if (s[i] == 'R' && b) {
				ans[i] = 'P';
				b--;
			}
			else if (s[i] == 'P' && c) {
				ans[i] = 'S';
				c--;
			}
			else if (s[i] == 'S' && a) {
				ans[i] = 'R';
				a--;
			}
		for (int i = 0; i < n; ++i)
			if (ans[i] == '@') {
				if (a) {
					ans[i] = 'R';
					a--;
				}
				else if (b) {
					ans[i] = 'P';
					b--;
				}
				else {
					ans[i] = 'S';
					c--;
				}
			}
		cout << ans << '\n';
	}
	return 0;
}
