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

int main(/*int argc, char*argv[]*/)
{
	int t; std::cin >> t;
	while(t --> 0)
	{
		int n; std::cin >> n;
		//iff parity same
		std::vector<int> vec(n);
		int64_t e1 = 0, o1 = 0;
		for(int i = 0; i < n; i++) std::cin >> vec[i], e1 += 1 - vec[i]%2, o1 += vec[i]%2;
		int m; std::cin >> m;
		std::vector<int> vec2(m);
		int64_t e2 = 0, o2 = 0;
		for(int i = 0; i < m; i++) std::cin >> vec2[i], e2 += 1 - vec2[i]%2, o2 += vec2[i]%2;
		std::cout << (e1*e2+o1*o2) << '\n';
	}
}
