#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll t, a, b, c, d, k, x, y;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int o = 1; o <= t; o ++)
	{
		cin >> a >> b >> c >> d >> k;
		x = (a / c) + (a % c != 0);
		y = (b / d) + (b % d != 0);
		if (x + y > k)
			cout << -1 << endl;
		else
			cout << x << " " << y << endl;
	}
	return 0;
}