#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define int long long
using namespace std;

signed main()
{
	int n;
	cin >> n;
	int counter = 0;
	int dev = -1;
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			if (dev == -1)
			{
				dev = i;
				counter++;
			}
			while (n % i == 0)
			{
				n /= i;
			}
			if (n % dev != 0 && dev % n != 0)
			{
				counter++;
				break;
			}
		}
	}
	if (counter == 2)
	{
		cout << "1\n";
	}
	if (counter == 1)
	{
		cout << dev << "\n";
	}
	if (counter == 0)
	{
		cout << n << "\n";
	}
}