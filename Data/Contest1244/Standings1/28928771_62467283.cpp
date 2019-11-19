#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, k;

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	while (T--)
	{
		cin >> a >> b >> c >> d >> k;
		int t1 = (a - 1) / c + 1, t2 = (b - 1) / d + 1;
		if (t1 + t2 > k) cout << -1 << endl;
		else cout << t1 << ' ' << t2 << endl;
	}
	return 0;
}
