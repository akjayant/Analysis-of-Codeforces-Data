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

	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
		{
		double a = 0, b = 0, c = 0, d = 0, k = 0;
		cin >> a >> b >> c >> d >> k;

		int pen = (int) ceil(a / c);
		int penc = (int) ceil(b / d);

		if (pen + penc <= k) cout << pen << " " << penc << "\n";
		else cout << -1 << "\n";
		}

	return 0;
	}