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

const int MAX_N = 1e5 + 7;

int n, m;

vector < int > cnt(MAX_N, 0);
vector < bool > _used(MAX_N, false);
int st = 1;
unordered_set < int > used;
set < pair < int , int > > _m;

queue < int > q[3];
int ans = 0;

void bfs()
{
	q[0].push(st);

	while (!q[0].empty() || !q[1].empty())
	{
		int now;

		if (!q[0].empty()) 
		{
			now = q[0].front();
			q[0].pop();
		}
		else 
		{
			now = q[1].front();
			q[1].pop();
			ans++;
		}

		//if (_used[now]) continue;

		used.erase(now);
		//_used[now] = true;

		int pls = -1;
		vector < int > u;
		for (auto it : used)
		{
			if (_m.find({min(now, it), max(now, it)}) == _m.end()) 
			{
				//q[0].push(it);
				u.push_back(it);
			}
			else 
			{
				pls = it;
			}
		}

		for (int i = 0; i < u.size(); i++)
		{
			used.erase(u[i]);
			q[0].push(u[i]);
		}

		if (q[0].empty() && pls != -1) q[1].push(pls);
	}
}

void read()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++) 
	{
		int x, y; cin >> x >> y;
		cnt[x]++, cnt[y]++;
		_m.insert({min(x, y), max(x, y)});
	}

	for (int i = 1; i <= n; i++) 
	{
		used.insert(i);
		if (cnt[st] > cnt[i]) st = i;
	}

	bfs();
}

void run()
{

}

void write()
{	
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); 

	read();
	run(); 
	write(); 

	return 0;
}
