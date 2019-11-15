#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")
#include"bits/stdc++.h"
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define ends ' '
#define endl '\n'
#define pb emplace_back
#define x first
#define y second
#define pii pair<int, int>
#define sz(x) (int)(x).size()

int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	IOS;

	int t;
	cin >> t;

	while(t--) {
		int ans = 0;

		int a, b, c;
		cin >> a >> b >> c;

		int sub = min(b, c/2);

		ans += 3*sub;
		b -= sub;
		c -= 2*sub;

		sub = min(a, b/2);

		ans += 3*sub;
		a -= sub;
		b -= 2*sub;

		cout << ans << '\n';
	}

	return 0;
}