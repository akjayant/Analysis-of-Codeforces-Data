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
int64_t modpow(int64_t a, int64_t b, int64_t mod = 1e9+7)
{
	int64_t cur = 1;
	//int64_t c2 = 1;
	while(b)
	{
		if(b & 1) cur *= a, cur %= mod;
		a *= a; a %= mod;
		b >>= 1;
	}
	return cur;
}
int main(/*int64_t argc, char*argv[]*/)
{
	int n; std::cin >> n;
	std::vector<std::vector<int>> vec(n, std::vector<int>(n));
	for(int x = 0; x < n; x++)
	{
		for(int y = 0; y < n; y++)
		{
			vec[y][x] = n * x + (x % 2 < 1 ? y + 1 : n - y);
		}
	}
	for(int y = 0; y < n; y++)
	{
		for(int el : vec[y]) printf("%d ", el);
		printf("\n");
	}
}
