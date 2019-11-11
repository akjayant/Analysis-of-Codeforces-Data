#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rnd(time(0));
#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
// #define int ll

void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	string s;
	cin >> s;
	string ans(n, '0');
	int wow = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'R' && b) {
			ans[i] = 'P';
			wow++;
			b--; 
		} else if(s[i] == 'P' && c) {
			ans[i] = 'S';
			wow++;
			c--;
		} else if(s[i] == 'S' && a) {
			ans[i] = 'R';
			wow++;
			a--;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ans[i] == '0') {
			if (a) {
				a--;
				ans[i] = 'R';
			}
			else if(b) {
				b--;
				ans[i] = 'P';
			}
			else if(c) {
				c--;
				ans[i] = 'S';
			}
		}
	}
	if (wow >= (n + 1) / 2) {
		cout << "YES" << endl;
		cout << ans << endl;
	} else {
		cout << "NO" << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}