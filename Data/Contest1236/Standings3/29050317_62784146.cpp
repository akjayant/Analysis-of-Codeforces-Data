// Author : Apaar
// Built  : 17-10-2019 19:07:28

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
		int a, b, c;
		cin >> a >> b >> c;
		while (c - 2 >= 0 && b - 1 >= 0) {
			ans += 3;
			c -= 2;
			b -= 1;
		}
		while (b - 2 >= 0 && a - 1 >= 0) {
			ans += 3;
			b -= 2;
			a -= 1;
		}
		cout << ans << '\n';
	}
}