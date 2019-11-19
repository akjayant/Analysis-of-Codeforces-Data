// -*- coding: utf-8 -*-
// @Date    : 2019-10-20 17:14:23

#include <bits/stdc++.h>
#define greeting cerr << "What's your problem?\n"

using namespace std;
typedef long long ll;

template<typename T>
ostream& operator << (ostream& os, const vector<T>& v)
{
	for(auto i : v)
		os << i << " ";
	return os;
}

template<typename T>
ostream& operator << (ostream& os, const set<T>& v)
{
	for(auto i : v)
		os << i << " ";
	return os;
}

const int N = 1e5 + 233;
ll a[N];

// #define local
int main()
{
#ifdef local
	freopen("data.in", "r", stdin);
	freopen("ans.out", "w", stdout);
#endif	
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%I64d", &a[i]);
	sort(a, a+n);
	ll x, y;
	x = y = 0;
	for(int i = 0; i < (n>>1); ++i)
		x += a[i];
	for(int i = (n>>1); i < n; ++i)
		y += a[i];
	printf("%I64d\n", x*x + y*y);
	return 0;
}