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
	long long a, b, c;
	long long t;
	cin >> t;
	for (int j = 0; j < t; j++)
	{
		queue <char> Q;
		long long n;
		cin >> n;
		vector <int> A(3);
		long long k = 0;
		cin >> a >> b >> c; // ������, ������, �������
		char temp = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			if (temp == 'R')
			{
				if (b > 0)
				{
					k++;
					b--;
					Q.push('P');
				}
				else
					Q.push('T');
			}
			if (temp == 'P')
			{
				if (c > 0)
				{
					k++;
					c--;
					Q.push('S');
				}
				else
					Q.push('T');
			}
			if (temp == 'S')
			{
				if (a > 0)
				{
					k++;
					a--;
					Q.push('R');
				}
				else
					Q.push('T');
			}
		}
		if (k >= (n + 1) / 2)
		{
			cout << "YES\n";
			while (!Q.empty())
			{
				if (Q.front() == 'T')
				{
					if (a > 0)
					{
						a--;
						cout << 'R';
					}
					else
					{
						if (b > 0)
						{
							b--;
							cout << 'P';
						}
						else
						{
							c--;
							cout << 'S';
						}
					}
				}
				else
					cout << Q.front();
				Q.pop();
			}
			cout << '\n';
		}
		else
			cout << "NO\n";
	}
	return 0;
}