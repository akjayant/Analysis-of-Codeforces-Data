#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
		int tac = (a/c) + (a%c != 0);
		int tbd = (b/d) + (b%d != 0);
		if(tac + tbd > k) cout << -1;
		else cout << tac << " " << tbd;
		cout << "\n";
	}
}