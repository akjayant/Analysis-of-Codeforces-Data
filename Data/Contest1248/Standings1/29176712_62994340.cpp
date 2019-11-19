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

#define MOD 1000000007

#define MED 1250


long long count_ways(int n)
{
	vector<vector<long long>> dp(n + 5, vector<long long>(2));
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			dp[i][j] += dp[i - 1][!j];
			if (i > 1)
				dp[i][j] += dp[i - 2][!j];
			dp[i][j] = dp[i][j] % MOD;
		}
	}

	return (dp[n - 1][0] + dp[n-1][1])%MOD;
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

	int n, m;
	cin >> n >> m;

	long long aa = (count_ways(n) + MOD - 2);
	long long bb = count_ways(m);

	cout << (aa + bb) % MOD;


	return 0;
}