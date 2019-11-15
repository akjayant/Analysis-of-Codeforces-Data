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

		vector < pair < int , int > > ans;

		for (int i = 0; i < n; i++)
		{
			//cout << s1 << " " << s2 << endl;

			if (s1[i] == s2[i]) continue;

			bool f = false;

			for (int j = i + 1; j < n; j++)
			{
				if (s1[j] == s2[j]) continue;

				if (s2[j] == s2[i])
				{
					swap(s2[j], s1[i]);
					ans.push_back({i, j});
					f = true;
					break;
				}
			}

			if (f) continue;

			//cout << "KEK" << endl;

			for (int j = i + 1; j < n; j++)
			{
				if (s1[j] == s2[j]) continue;

				if (s1[j] == s2[i])
				{
					swap(s1[j], s2[j]);
					ans.push_back({j, j});
					swap(s1[i], s2[j]);
					ans.push_back({i, j});
					f = true;
					break;
				}
			}
		}

		if (s1 != s2) { cout << "NO" << endl; continue; }

		cout << "YES" << endl;
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;	
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
