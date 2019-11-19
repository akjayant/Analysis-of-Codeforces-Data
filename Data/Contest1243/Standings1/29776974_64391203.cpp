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

long long n;

// long long __gcd(long long a, long long b)
// {
// 	if (a == 0) return b;
// 	if (a > b) return __gcd(b, a);
// 	return __gcd(b % a, a);
// }


void read()
{
	cin >> n;

	long long d = 1;
	long long mini = n + 1;
	long long cnt = 0;

	for (long long i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			mini = min(mini, i);

			cnt++;

			if (d == 1)
			{
				if (cnt > 1) break;
				else d = __gcd(i, n / i);
			}
			else 
			{
				d = __gcd(d, i);
				d = __gcd(d, n / i);
			}
		}
	}

	if (mini == n + 1) cout << n;
	else cout << d;
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
