#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int x = (a - 1) / c + 1;
		int y = (b - 1) / d + 1;
		if(x + y <= k) cout << x << " " << y << "\n";
		else cout << "-1\n";
	}
	return 0;
}