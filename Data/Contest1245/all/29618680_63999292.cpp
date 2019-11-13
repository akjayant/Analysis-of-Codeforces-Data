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
		int n, r, p, s; std::cin >> n >> r >> p >> s;
		std::string moves; std::cin >> moves;
		int rb=0, pb=0, sb=0;
		for(char c : moves)
			if(c == 'R') rb++;
			else if(c == 'P') pb++;
			else if(c == 'S') sb++;
		//move greedily to win
		int victories = std::min(r, sb) + std::min(p, rb) + std::min(s, pb);
		std::string vs = moves;
		for(int i = 0; i < n; i++)
			if(r != 0 && moves[i] == 'S') vs[i] = 'R', r--;
			else if(p != 0 && moves[i] == 'R') vs[i] = 'P', p--;
			else if(s != 0 && moves[i] == 'P') vs[i] = 'S', s--;
			else vs[i] = 'X';
		for(int i = 0; i < n; i++)
			if(vs[i] == 'X' && r != 0) vs[i] = 'R', r--;
			else if(vs[i] == 'X' && p != 0) vs[i] = 'P', p--;
			else if(vs[i] == 'X' && s != 0) vs[i] = 'S', s--;
		if(victories < (n + 1) / 2) std::cout << "NO\n";
		else
			std::cout << "YES\n" << vs << '\n';
	}
	return 0;
}
