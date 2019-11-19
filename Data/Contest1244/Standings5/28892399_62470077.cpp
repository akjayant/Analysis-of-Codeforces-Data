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
		int n = 0;
		cin >> n;
		string l = {};
		cin >> l;

		int lb = 0, rb = 0;
		for (int j = 0; j < l.size(); j++)
			{
			if (l[j] == '1')
				{
				lb = j + 1;
				break;
				}
			}
		for (int j = l.size() - 1; j >= 0; j--)
			{
			if (l[j] == '1')
				{
				rb = j + 1;
				break;
				}
			}

		if (rb != 0 && lb != 0)
			{
			if (rb >= l.size() - lb + 1) cout << 2 * rb << "\n";
			else cout << 2 * (l.size() - lb + 1) << "\n";
			}
		else cout << l.size() << "\n";
		}

	return 0;
	}