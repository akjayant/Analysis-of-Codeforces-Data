#include <bits/stdc++.h>

#define boost ios_base::sync_with_stdio(false), cin.tie(NULL);

using namespace std;
const int N = 1e6 + 55;
const int mod = 1e9 + 7;
const long long INF = 1e18 + 12;
const int inf = 1e9;

int a[N];

int main () {
	boost;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0 ; i < n ; ++ i) {
			cin >> a[i];
		}
		sort (a, a + n);
		reverse (a, a + n);
		int ans = 1;
		for (int i = 0 ; i < n ; ++ i) {
			if (a[i] >= i + 1) ans = i + 1;
		}
		cout << ans << "\n";
	}
}