//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

int q;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int a[n + 17] = {};
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		int ans = 0, mn = a[n];
		for (int i = n; i > 0; i--) {
			mn = min(mn, a[i]);
			ans = max(ans, min(mn, (n - i + 1)));
		}
		cout << ans << endl;
	}
	return 0;
}
