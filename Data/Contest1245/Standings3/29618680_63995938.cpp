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

int gcd(int a, int b)
{
	if(a == 0 || b == 0) return a+b;
	return gcd(b, a%b);
}
int main(/*int argc, char*argv[]*/)
{
	int t; std::cin >> t;
	while(t --> 0)
	{
		int a, b; std::cin >> a >> b;
		std::cout << (gcd(a, b) == 1 ? "Finite" : "Infinite") << '\n';
	}
	return 0;
}
