#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define endl '\n'

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	while (c >= 2 && b >= 1) {
		--b, c -= 2, ans += 3;
	}
	while (a >= 1 && b >= 2) {
		--a, b -= 2, ans += 3;
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed << setprecision(20);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) solve();
}