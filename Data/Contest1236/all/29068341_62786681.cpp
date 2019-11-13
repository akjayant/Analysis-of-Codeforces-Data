
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fr, to)    for (int i = fr; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

int ts, a, b, c, ans;

int main() {
	cin >> ts;
	cont (cs, ts) {
		ans = 0;
		cin >> a >> b >> c;
		circ (i, 0, a) {
			for (int k = 0; k <= c; k += 2) {
				int j = i * 2 + k / 2;
				if (j > b)  break;
				ans = max(ans, i + j + k);
			}
		}
		cout << ans << ln;
	}
}