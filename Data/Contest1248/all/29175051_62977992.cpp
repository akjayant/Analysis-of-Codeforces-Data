// Author : Apaar
// Built  : 20-10-2019 14:39:34

#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		int a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		cin >> m;
		int b[m];
		for (i = 0; i < m; i++) {
			cin >> b[i];
			if (b[i] & 1) cnt++;
		}
		for (i = 0; i < n; i++) {
			if (a[i] & 1) ans += cnt;
			else ans += (m - cnt);
		}
		cout << ans << '\n';
	}
}