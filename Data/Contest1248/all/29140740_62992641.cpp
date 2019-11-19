// -*- coding: utf-8 -*-
// @Date    : 2019-10-20 17:32:54

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
const ll MOD = 1e9 + 7;
ll f[N];

// #define local
int main()
{
#ifdef local
	freopen("data.in", "r", stdin);
	freopen("ans.out", "w", stdout);
#endif	
	ll x, y;
	scanf("%I64d%I64d", &x, &y);
	if(x > y)
		swap(x, y);
	f[1] = 2;
	f[2] = 4;
	for(int i = 3; i <= y; ++i)
		f[i] = (f[i-1] + f[i-2]) % MOD;
	printf("%I64d\n", (f[y] + f[x] - 2) % MOD);
	return 0;
}