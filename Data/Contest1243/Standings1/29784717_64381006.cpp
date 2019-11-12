#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
#include <regex>
#include <queue>
#include <string>
#include <set>

typedef  long long lol;
using namespace std;

#define fori(i,j,k) for (int (i)=(j);(i) < (k);(i)++)
#define MOD 4294967296ULL
#define EPS 0.000000001

void solve()
{
	int n;
	cin >> n;

	string s, t;
	cin >> s >> t;

	int prev_idx = -1;
	bool fail = false;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != t[i])
		{
			if (prev_idx == -1)
				prev_idx = i;
			else if (fail)
			{
				cout << "No\n";
				return;
			}

			else 
			{
				if (s[i] == s[prev_idx] && t[i] == t[prev_idx])
				{
					fail = true;
					continue;
				}
				cout << "No\n";
				return;
			}
		}
	}
	if (fail)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main() {

#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		solve();
	}
	


	return 0;
}