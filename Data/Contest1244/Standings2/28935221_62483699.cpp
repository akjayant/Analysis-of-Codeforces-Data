#include <map>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#define R register
#define ll long long
using namespace std;

int n;
ll k;
map<int, int> times;

template <class T> inline void read(T &x) {
	x = 0;
	char ch = getchar(), w = 0;
	while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x = w ? -x : x;
	return;
}

int main() {
	int x;
	read(n), read(k);
	for (R int i = 1; i <= n; ++i)
		read(x), ++times[x];
	while (k) {
		auto i = times.begin(), j = prev(times.end());
		if (i == j) break;
		if (i->second <= j->second) {
			auto u = next(i);
			ll del = u->first - i->first;
			if (del * i->second <= k)
				k -= del * i->second, u->second += i->second, times.erase(i);
			else {
				ll dis = k / i->second;
				cout << j->first - i->first - dis << endl;
				return 0;
			}
		}
		else {
			auto u = prev(j);
			ll del = j->first - u->first;
			if (del * j->second <= k)
				k -= del * j->second, u->second += j->second, times.erase(j);
			else {
				ll dis = k / j->second;
				cout << j->first - i->first - dis << endl;
				return 0;
			}
		}
	}
	cout << 0 << endl;
	return 0;
}