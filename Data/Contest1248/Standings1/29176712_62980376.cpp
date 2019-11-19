#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <math.h>
#include <map>
#include <functional>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define MOD 1000000009

#define MED 1250

void solve()
{
	int n;
	cin >> n;

	long long a[2] = { 0,0 };
	long long b[2] = { 0,0 };
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		a[tmp % 2]++;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		b[tmp % 2]++;
	}

	long long ans = a[0] * b[0] + a[1] * b[1];
	cout << ans << "\n";
}

int main()
{
#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t-- > 0)
	{
		solve();
	}

	


	return 0;
}