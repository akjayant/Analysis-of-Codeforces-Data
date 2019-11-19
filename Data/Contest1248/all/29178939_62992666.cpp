#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <array>
#include <valarray>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <set>
#include <map>
#include <random>
#include <iterator>
#include <numeric>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
using namespace std::string_literals;

int64_t solve(int64_t n)
{
	std::vector<std::vector<int>> dp(n, std::vector<int>(2));
	dp[0][0] = 1;
	for(int i = 1; i < n; i++)
	{
		dp[i][1] = dp[i-1][0];
		dp[i][0] = (dp[i-1][1] + dp[i-1][0]) % int64_t(1e9+7);
	}
	return (dp[n-1][0] + dp[n-1][1])%int64_t(1e9+7);
}
int64_t fib(int64_t n) 
{ 
	int64_t n1 = 0, n2 = 1, n3 = 0, i = 0;
	if(!n)
		return 0;
	for (i = 2; i <= n; i++)
	{
		n3 = (n1 + n2) % int64_t(1e9+7);
		n1 = n2;
		n2 = n3;
	}
	return n2;
}
int main(/*int argc, char*argv[]*/)
{
	////calculate number such that no more than 1 DIFFERENT cell
	////11
	////10 can't be a subpattern (and so can't many similar ones)
	////therefor
	////2 * n + 2 * m - 2 (two configurations end up being counted twice)
	int n, m; std::cin >> n >> m;
	std::cout << ((2ll * (solve(n) + solve(m)) - 2ll) % int64_t(1e9+7)) << '\n';

}
