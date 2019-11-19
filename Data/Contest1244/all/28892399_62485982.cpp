#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <cmath>
#include <set>

#define int					long long
#define all(q)				q.begin(), q.end()

using namespace std;

signed main()
	{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(20);

	long long w = 0, d = 0, p = 0, ans2 = 0, ans1 = 0, n = 0;
	cin >> n >> p >> d >> w;

	int q = w, r = d;
	while (q != 1 && r != 0)	q %= r, swap(q, r);

	if (p % q != 0) cout << -1 << "\n";
	else
		{
		while ((w * ans2 - p) % d != 0)	ans2++;
		ans1 = -(w * ans2 - p) / d;

		if (ans1 < 0 || ans2 < 0) cout << -1 << endl;
		else
			{
			if (ans1 + ans2 > n) cout << "-1" << endl;
			else cout << ans1 << " " << ans2 << " " << n - ans1 - ans2 << endl;
			}
		}

	return 0;
	}