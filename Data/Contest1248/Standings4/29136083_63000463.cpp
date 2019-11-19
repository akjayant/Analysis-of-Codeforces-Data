/*#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("Ofast")*/

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdio>
#include <string>
#include <bitset>
#include <vector>
//#include <random>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <map>
#include <set>

using namespace std;

const long double PI = 3.14159265358979323846264338328;
const long long mx64 = 9223372036854775807;
const int mx32 = 2147483647;
const short int mx16 = 32767;
const long long mod1 = 1000000007;
const long long mod2 = 998244353;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(25);

	int n, m;
	cin >> n >> m;
	long long ans = 0;

	vector<long long> bp(m + 1, 1);
	for (int i = 1; i <= m; i++) {
		bp[i] = (2 * bp[i - 1]) % mod1;
	}

	vector<long long> dp1(n + 1, 2);
	for (int i = 2; i <= n; i++) {
		dp1[i] = (dp1[i - 1] + dp1[i - 2]) % mod1;
	}

	vector<long long> dp(m + 1, 2);
	for (int i = 2; i <= m; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod1;
	}

	cout << (dp1[n] + dp[m] - 2 + mod1) % mod1;

	//cout << dp[m];
	//cout << "\n"; system("pause");
	return 0;
}
/*

*/