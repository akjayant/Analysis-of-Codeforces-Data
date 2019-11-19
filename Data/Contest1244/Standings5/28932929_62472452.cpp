#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double


signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string a;
		cin >> a;
		bool a1 = 0;
		int nach = 0;
		int h = 0;
		for (int i = 0; i < n; i++) {
			if (!a1 && a[i]-'0' == 1) {
				a1 = 1;
				nach = i + 1;
			}
			if (a[i]-'0') h = i+1;
		}
		if (a1 == 0) cout << n << endl;
		else {
			cout << max( 2 * nach, max(2 * n - 2 * nach + 2, max(2 * h , 2* n - 2 * h + 2 )))<< endl;
		}

		
	}
}