#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int  main()
{
	int n, a, b, c, d, k;
	cin >> n;
	while(n--)
	{
		cin >> a >> b >> c >> d >> k;
		int f = (a / c) + (a % c > 0), h = (b / d) + (b % d > 0);
		if (f + h > k)
			cout << -1 << endl;
		else cout << f << ' ' << h << endl;
	}
	return 0;
}