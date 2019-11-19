#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <assert.h>

using namespace std;

#define ll long long
#define ull unsigned long long
const ll INF = 1e18;
const double PI = acos(-1.0);

const int MAX_N = 100005;
const ll MOD = 1e9 + 7;
ll dpA[MAX_N], dpB[MAX_N];

int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	dpA[0] = dpB[0] = dpA[1] = dpB[1] = 1;
	for (int i = 2; i < MAX_N; i++)
	{
		dpA[i] = dpB[i - 1] + dpB[i - 2];
		dpB[i] = dpA[i - 1] + dpA[i - 2];
		dpA[i] %= MOD;
		dpB[i] %= MOD;
	}

	ll res = (dpA[n] + dpB[n] + dpA[m] + dpB[m] + MOD - 2) % MOD;
	cout << res;

	//system("pause");
	return 0;
}