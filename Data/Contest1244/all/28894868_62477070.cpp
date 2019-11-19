
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fr, to)    for (int i = fr; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

int ts, n, ans;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> ts;
	cont (cs, ts) {
		cin >> n >> s;
		s = ' ' + s;
		ans = n;
		int mn = -1, mx = -1;
		cont (i, n) {
			if (s[i] != '1')  continue;
			if (mn == -1 || i < mn) {
				mn = i;
			}
			if (mx == -1 || i > mx) {
				mx = i;
			}
		}
		if (mn > -1) {
			ans = max(ans, (n - mn + 1) * 2);
		}
		if (mx > -1) {
			ans = max(ans, mx * 2);
		}
		cout << ans << ln;
	}
}