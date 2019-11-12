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

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end(), std::greater<int>());
	int best = 0;
	for (int j = 0; j < vec.size(); j++)
	{
		int len = j + 1;
		int sz = vec[j];
		if (sz < len)
			break;
		best = max(best, len);
	}

	cout << best << "\n";
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