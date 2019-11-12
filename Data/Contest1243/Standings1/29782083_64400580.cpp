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
#include <list>

int main(/*int argc, char*argv[]*/)
{
	int t; std::cin >> t;
	while(t --> 0)
	{
		int n; std::cin >> n;
		std::string s, t; std::cin >> s >> t;
		std::vector<std::pair<int,int>> swaps;
		for(int i = 0; i < n; i++)
		{
			//printf("s=%s, t=%s\n", s.data(), t.data());
			char c = s[i];
			if(c == t[i]) continue;
			//find such char in s
			bool done = false;
			for(int j = i + 1; j < n; j++)
			{
				if(s[j] != c) continue;
				done = true;
				swaps.push_back({j, i});
				std::swap(s[j], t[i]);
				break;
			}
			if(done) continue;
			for(int j = i + 1; j < n; j++)
			{
				if(t[j] != c) continue;
				done = true;
				swaps.push_back({j, j});
				std::swap(s[j], t[j]);
				swaps.push_back({j, i});
				std::swap(s[j], t[i]);
				break;
			}
		}
		if(s != t) std::cout << "No\n";
		else
		{
			std::cout << "Yes\n";
			std::cout << swaps.size() << '\n';
			for(auto[i, j] : swaps)
				printf("%d %d\n", i+1, j+1);
		}
	}
}

