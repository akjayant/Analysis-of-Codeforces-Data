/**
	© 2017-2019 Tai-Yuan Kuo All Rights Reserved.
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define rfor0(i, n) for(int i = n - 1; i >= 0; --i)
#define rfor1(i, n) for(int i = n; i > 0; --i)
#define all(it, a) for(auto it = (a).begin(); it != (a).end(); ++it)
#define rall(it, a) for(auto it = (a).rbegin(); it != (a).rend(); ++it)
#define rep for0

stringstream output;

/** Actually outputs the result and end the program.*/
inline void eOP();

inline void solve()
{
	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;

	int x = a / c + !!(a % c);
	int y = b / d + !!(b % d);

	if (x + y > k)
	{
		cout << "-1\n";
		return;
	}
	cout << x << " " << y << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	size_t t = 1;
	cin >> t;
	rep (i, t)
	{
		solve();
	}

	eOP();
}

inline void eOP()
{
	cout << output.str();
	output.str(string());
	exit(0);
}
