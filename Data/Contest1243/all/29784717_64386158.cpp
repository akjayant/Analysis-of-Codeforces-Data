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

	map<char, int> mm;
	for (char c : s)
		mm[c]++;
	for (char c : t)
		mm[c]++;
	for (auto x : mm)
	{
		if (x.second % 2 == 1)
		{
			cout << "No\n";
			return;
		}
	}

	vector < pair<int, int>> ans;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == t[i])
			continue;

		bool ok = false;
		// let's keep s[i]
		for (int j = i + 1; j < n; j++)
		{
			if (s[j] == s[i])
			{
				ans.push_back({ j, i });
				swap(s[j], t[i]);
				ok = true;
				break;
			}
		}

		if (ok)
			continue;

		for (int j = i + 1; j < n; j++)
		{
			if (t[j] == s[i])
			{
				ans.push_back({ j, j });
				swap(s[j], t[j]);
				ans.push_back({ j, i });
				swap(s[j], t[i]);
				ok = true;
				break;
			}
		}
	}

	cout << "Yes\n";
	cout << ans.size() << "\n";
	for (auto x : ans)
	{
		cout << x.first + 1 << " " << x.second + 1 << "\n";
	}

	if (s != t)
		throw 1;
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