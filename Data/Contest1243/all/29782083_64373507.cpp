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
		std::vector<int> vec(n);
		for(int i = 0; i < n; i++) std::cin >> vec[i];
		std::sort(vec.rbegin(), vec.rend());
		int max = -1;
		for(int s = 1; s <= n; s++)
		{
			bool bad = false;
			for(int i = 0; i < s; i++)
				if(vec[i] < s) bad = true;
			if(!bad) max = s;
		}
		std::cout << max << '\n';
	}
}

