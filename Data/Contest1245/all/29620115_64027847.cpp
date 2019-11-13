#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int a, b, c;
		cin >> a >> b >> c;

		string s;
		cin >> s;

		int a2 = count(s.begin(), s.end(), 'R'), 
		    b2 = count(s.begin(), s.end(), 'P'),
		    c2 = count(s.begin(), s.end(), 'S');

		string ans(n, ' ');
		int win = min(a, c2) + min(b, a2) + min(c, b2);

		if (2*win >= n) {
			cout << "YES\n";

			int at = 0;
			for (char ch : s) {
				if (a > 0 and ch =='S') {
					a--;
					ans[at] = 'R';
				}
				if (b > 0 and ch == 'R') {
					b--;
					ans[at] = 'P';
				}
				if (c > 0 and ch == 'P') {
					c--;
					ans[at] = 'S';
				}
				at++;
			}

			for (char& ch : ans) {
				if (ch == ' ') {
					if (a > 0) ch = 'R', a--;
					else if (b > 0) ch = 'P', b--;
					else ch = 'S', c--;
				}
			}

			cout << ans << "\n";
		}
		else cout << "NO\n";
	}
}