#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
 
int t, a, b, c;
int ans;

signed main() {
	Hina;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c;
		ans = min(c/2, b);
		b -= ans;
		ans += min(b/2, a);
		cout << ans*3 << endl;
	}
	return 0;
}