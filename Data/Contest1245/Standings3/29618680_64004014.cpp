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

int64_t MOD = 1e9+7;
int fib(int at)
{
	int a = 0, b = 1, c = 0;
	if(at == 0) return 0;
	for(int i = 2; i <= at; i++)
	{
		c = a + b;
		c %= MOD;
		a = b;
		b = c;
	}
	return b % MOD;
}
int main(/*int argc, char*argv[]*/)
{
	std::string s; std::cin >> s;
	int64_t runu = 0, runn = 0;
	int64_t ans = 1;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'u') runu++;
		else if(runu != 0)
			ans *= fib(runu+1), ans %= MOD, runu = 0;// * (runu - 1) / 2

		if(s[i] == 'n') runn++;
		else if(runn != 0)
			ans *= fib(runn+1), ans %= MOD, runn = 0;// * (runn - 1) / 2

		if(s[i] == 'w' || s[i] == 'm') ans = 0;
	}
	if(runu != 0)
		ans *= fib(runu+1), ans %= MOD;
	if(runn != 0)
		ans *= fib(runn+1), ans %= MOD;
	std::cout << ans;
	return 0;
}
