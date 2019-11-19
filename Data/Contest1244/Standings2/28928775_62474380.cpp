#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int  main()
{
	long long n, p, w, d;
	cin >> n >> p >> w >> d;
	for(long long
	i = 0; i < w; i++)
		if (p >= i * d && (p - i * d) % w == 0 && ((p - i * d) / w) + i <= n)
		{
			long long x = (p - i * d) / w;
			cout << x << ' ' << i << ' ' << n - i - x;
			return 0;
		}
	cout << -1;
	return 0;
}