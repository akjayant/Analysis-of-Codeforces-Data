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

int main(/*int64_t argc, char*argv[]*/)
{
	int n; std::cin >> n;
	while(n --> 0)
	{
		int a, b, c; std::cin >> a >> b >> c;
		int cur = 0;
		int t = 0;
		t = std::min(c / 2, b);
		b -= t;
		cur += t * 3;
		c -= t;
		t = std::min(b / 2, a);
		cur += t * 3;
		std::cout << cur << '\n';
	}
	return 0;
}
