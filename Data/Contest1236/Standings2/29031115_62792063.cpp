// -*- coding: utf-8 -*-
// @Date    : 2019-10-17 21:50:33

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

const int N = 2050;
int a[N][N];

// #define local
int main()
{
#ifdef local
	freopen("data.in", "r", stdin);
	freopen("ans.out", "w", stdout);
#endif	
	int n;
	scanf("%d", &n);
	int cur = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(i&1)
			for(int j = 1; j <= n; ++j)
				a[i][j] = ++cur;
		else
			for(int j = n; j; --j)
				a[i][j] = ++cur;
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			printf("%d ", a[j][i]);
		printf("\n");
	}
	return 0;
}