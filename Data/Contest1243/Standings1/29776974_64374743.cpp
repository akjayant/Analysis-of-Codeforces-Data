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

int n; 
int k; 

void read()
{
	cin >> n;

	for (int i = 1; i <= n; i++) 
	{
		cin >> k;
		int a[k + 10]; for (int j = 1; j <= k; j++) cin >> a[j], a[j] *= -1;

		sort(a + 1, a + 1 + k);

		int maxi = 1;

		for (int j = 1; j <= k; j++)
		{
			a[j] *= -1;

			maxi = max(maxi, min(j, a[j]));
		}

		cout << maxi << endl;
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
