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
	int n; std::cin >> n;
	std::vector<int> vec(n);
	for(int i = 0; i < n; i++) std::cin >> vec[i];
	std::sort(vec.rbegin(), vec.rend());
	int64_t sum = 0;
	int64_t res = 0;
	int i = 0;
	for(; i < (n + 1) / 2; i++)
	{
		sum += vec[i];
	}
	res += sum * sum;
	sum = 0;
	for(;i < n; i++)
	{
		sum += vec[i];
	}
	res += sum * sum;
	std::cout << res << '\n';
}
