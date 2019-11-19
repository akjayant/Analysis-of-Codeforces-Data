// -*- coding: utf-8 -*-
// @Date    : 2019-10-20 16:45:10

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
int a[N], b[N];

// #define local
int main()
{
#ifdef local
	freopen("data.in", "r", stdin);
	freopen("ans.out", "w", stdout);
#endif	
	int T;
	scanf("%d", &T);
	while(T--)
	{
		ll x, y, z, w;
		x = y = z = w = 0;
		int n, m;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", a+i);
			if(a[i]&1)
				++x;
			else
				++y;
		}
		scanf("%d", &m);
		for(int i = 0; i < m; ++i)
		{
			scanf("%d", b+i);
			if(b[i]&1)
				++z;
			else
				++w;
		}
		printf("%I64d\n", x*z + y*w);
	}
	return 0;
}