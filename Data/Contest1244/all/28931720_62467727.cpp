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
		int n; std::cin >> n;
		std::string s; std::cin >> s;
		int fz = INT_MAX, lz = -1;
		for(int i = 0; i < n; i++)
			if(s[i] == '0') continue;
			else fz = std::min(fz, i),
				lz = i;
		if(lz == -1) std::cout << n << '\n';
		else std::cout << (2*n - 2*std::min(fz, n - lz - 1)) << '\n';
	}
}
