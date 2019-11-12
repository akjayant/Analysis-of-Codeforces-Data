//#include<bits/stdc++.h>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

int k, n;
string s1, s2;

void read()
{
	cin >> k;

	for (int _k = 1; _k <= k; _k++)
	{
		cin >> n;
		cin >> s1 >> s2;

		vector < int > a;

		for (int i = 0; i < n; i++)
		{
			if (s1[i] != s2[i]) a.push_back(i);
		}

		if (a.size() <= 1 || a.size() > 2)
		{
			cout << "NO" << endl;
		}
		else 
		{
			int p1 = a[0], p2 = a[1];

			swap(s1[p1], s2[p2]);

			if (s1 == s2)
			{
				cout << "YES" << endl;
			}
			else 
			{
				swap(s1[p1], s2[p2]);
				swap(s1[p2], s2[p1]);

				if (s1 == s2)
				{
					cout << "YES" << endl;
				}
				else 
				{
					cout << "NO" << endl;
				}
			}
		}
	}
}

void run()
{

}

void write()
{

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); 

	read();
	run(); 
	write(); 

	return 0;
}
