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
	int q; std::cin >> q;
	while(q --> 0)
	{
		int a, b, c, d, k; std::cin >> a >> b >> c >> d >> k;
		int pencils = (a + c - 1) / c;
		int pens = (b + d - 1) / d;
		if(pens + pencils > k) std::cout << "-1\n";
		else std::cout << pencils << " " << pens << '\n';
	}
}
