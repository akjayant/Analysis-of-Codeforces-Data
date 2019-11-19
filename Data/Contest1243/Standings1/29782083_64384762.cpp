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

int64_t gcd(int64_t a, int64_t b)
{
	if(a == 0 || b == 0) return a+b;
	return gcd(b, a%b);
}
int main(/*int argc, char*argv[]*/)
{
	int64_t n; std::cin >> n;
	int divs = 0, d1 = 0;
	int64_t mg = LLONG_MAX;
	for(int64_t i = 2; i*i <= n; i++)
	{
		if(n % i == 0)
		{
			divs += 2;
			if(d1 == 0) d1 = i;
			mg = std::min(mg, gcd(i, n/i));
		}
		if(i * i == n) divs--;
	}
	std::cout << (mg == LLONG_MAX ? n : mg) << '\n';
	return 0;
}

