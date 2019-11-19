#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("1244A.in", "r", stdin);
	#endif

	int t, a, b,c , d, k;
	
	cin >> t;

	while (t--)
	{
		cin >> a >> b >> c >> d >> k;
		int pen, pencil;
		pen = (a - 1) / c  + 1;
		pencil = (b - 1) / d + 1;

		if (pen + pencil <= k)
		{
			cout << pen << " " << pencil << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}