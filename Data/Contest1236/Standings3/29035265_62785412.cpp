#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define mod 1000000007
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, t;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		int y = min(b, c / 2);
		int ans = 3 * y;
		b -= y;
		ans += 3 * min(a, b / 2);
		cout << ans << '\n';
	}
	return 0;
}