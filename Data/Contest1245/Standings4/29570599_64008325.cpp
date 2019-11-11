#include <bits/stdc++.h>
#define mp make_pair
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
typedef long long LL;
const int maxn = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
int t, n, a, b, c, cr, cp, cs, cnt;
string str, ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> a >> b >> c >> str;
		cnt = cr = cp = cs = 0;
		ans = "";
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == 'R' && b) {
				ans += "P";
				++cnt;
				--b;
			}
			else if (str[i] == 'P' && c) {
				ans += "S";
				++cnt;
				--c;
			}
			else if (str[i] == 'S' && a) {
				--a;
				ans += "R";
				++cnt;
			}
			else
				ans += " ";
		}
		if (cnt >= (n + 1) / 2) {
			cout << "YES" << endl;
			for (int i = 0; i < ans.size(); ++i) {
				if (ans[i] == ' ') {
					if (a) {
						ans[i] = 'R';
						--a;
					}
					else if (b) {
						ans[i] = 'P';
						--b;
					}
					else if (c) {
						ans[i] = 'S';
						--c;
					}
				}
			}
			cout << ans << endl;
		}
		else
			cout << "NO" << endl;
	}
}