#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<int> nextRand(0, (int)1e9);
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long a, b;
	long long t;
	cin >> t;
	for (int j = 0; j < t; j++)
	{
		bool fl = true;
		cin >> a >> b;
		if ((a == b) && (a != 1))
			fl = false;
		for (long long i = 2; i <= min(a, b); i++)
		{
			if ((a % i == 0) && (b % i == 0))
			{
				fl = false;
				break;
			}
		}
		if (fl)
			cout << "Finite\n";
		else
			cout << "Infinite\n";
	}
	return 0;
}