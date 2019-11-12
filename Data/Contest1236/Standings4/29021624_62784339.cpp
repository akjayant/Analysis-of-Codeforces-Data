#include <bits/stdc++.h>
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define out(t, a) copy(all(a), ostream_iterator<t>(cout, " ")); cout << "\n";
// #define DEBUG
 
using namespace std;
 
void set_program() {
	#ifdef DEBUG
		freopen ("test.in", "r", stdin);
		freopen ("test.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
 
// typedef long long ll;
 
// const int INF = 1e9 + 1;
 
main() {
	set_program();
	int t;
	cin >> t;
	for (; t--; ) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		for (int cnt1 = 0; cnt1 < 100; ++cnt1) {
			for (int cnt2 = 0; cnt2 < 100; ++cnt2) {
				if (a >= cnt1 && b >= 2 * cnt1 + cnt2 && c >= 2 * cnt2) {
					ans = max(ans, 3 * cnt1 + 3 * cnt2);
				}
			}
		}
		cout << ans << "\n";
	}
 	return 0;
}
