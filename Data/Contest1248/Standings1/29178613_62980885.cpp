#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <assert.h>

using namespace std;

#define ll long long
#define ull unsigned long long
const ll INF = 1e18;
const double PI = acos(-1.0);



int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		int n, m;
		cin >> n;
		ll a;
		ll x0 = 0, x1 = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			if (a % 2 == 0)
				x0++;
			else
				x1++;
		}
		cin >> m;
		ll y0 = 0, y1 = 0;
		for (int i = 0; i < m; i++)
		{
			cin >> a;
			if (a % 2 == 0)
				y0++;
			else
				y1++;
		}
		ll res = x0 * y0 + x1 * y1;
		cout << res << endl;
	}

	//system("pause");
	return 0;
}