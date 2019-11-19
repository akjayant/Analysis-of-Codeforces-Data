#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int  main()
{
	int n, t;
	string s;
	cin >> n;
	while(n--)
	{
		cin >> t;
		cin >> s;
		int i, j;
		for (i = 0; i < t; i++)
			if (s[i] == '1')
				break;
		if (i == t)
		{
			cout << t << endl;
			continue;
		}
		for (j = t - 1; j >= 0; j--)
			if (s[j] == '1')
				break;
		cout << 2 * max(t - i, j + 1) << endl;
	}
	return 0;
}