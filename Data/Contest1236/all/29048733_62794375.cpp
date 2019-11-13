#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define MAXN 300
using namespace std;
 
int n, k;
int ans[MAXN+5][MAXN+5];

signed main() {
	Hina;
	cin >> n;
	for (int j = 0; j < n; j++) {
		if (j % 2) {
			for (int i = n-j; i < 2*n-j; i++) {
				ans[(i+n)%n][j] = ++k;
			}
		} else {
			for (int i = n-j; i > -j; i--) {
				ans[(i+n)%n][j] = ++k;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}