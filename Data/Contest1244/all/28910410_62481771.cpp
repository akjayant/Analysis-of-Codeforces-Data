#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; cin >> s;
		int dl = 0, df = n-1;
		while(s[dl] != '1') {
			dl++; if(dl == n) break;
		}
		while(s[df] != '1') {
			df--; if(df == -1) break;
		}
		if(df == -1) cout << n << "\n";
		else {
			if(dl >= n - 1 - df) {
				cout << 2 * (df+1) << "\n";
			} else {
				cout << 2*(n - dl) << "\n";
			}
		}
	}
}