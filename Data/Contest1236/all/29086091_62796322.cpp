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
	int n, m; std::cin >> n >> m;
	std::cout << modpow((modpow(2, m) + int(1e9)+6)%(int(1e9)+7),n) << '\n';
}
