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

int main(/*int argc, char*argv[]*/)
{
	int k; std::cin >> k;
	while(k --> 0)
	{
		int n; std::cin >> n;
		std::string s, t; std::cin >> s >> t;
		//only two differences in map
		int i1 = 0, i2 = 0;
		int diffs = 0;
		for(int i = 0; i < n; i++)
			if(s[i] != t[i])
			{
				if(diffs == 0) i1 = i, diffs++;
				else if(diffs == 1) i2 = i, diffs++;
				else diffs++;
			}
		std::swap(s[i1], t[i2]);
		std::cout << (s == t ? "Yes\n" : "No\n");
	}
}

