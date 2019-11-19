#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <string>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
#include <ctime>
#include <utility>
#include <bitset>
#include <random>
#include <iostream>
#include <iterator>
#include <stack>
#include <list>
#include <fstream>

using namespace std;

const long long INF = numeric_limits<long long>::max();
const int MOD = 1000 * 1000 * 1000 + 7;
const int BASE = 257;
const double PI = 2 * acos(0.0);

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int l = 0;
		int r = n - 1;
		while (l < n)
		{
			if (s[l] == '1')
				break;
			else
				l++;
		}

		while (r >= 0)
		{
			if (s[r] == '1')
				break;
			else
				r--;
		}

		if (l == n && r == -1)
			l = r = -1;

		if (l == -1)
		{
			cout << n << endl;
		}
		else
		{
			int m = min(l, n - r - 1);
			cout << 2 * (n - m) << endl;
		}
	}
	return 0;
}
