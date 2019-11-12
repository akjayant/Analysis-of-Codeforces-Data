// -*- coding: utf-8 -*-
// @Date    : 2019-10-17 21:45:36

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

const ll MOD = 1e9 + 7;

ll fp(ll x, ll y)
{
	ll res = 1;
	while(y)
	{
		if(y&1)
			res *= x;
		x *= x;
		y >>= 1;
		x %= MOD;
		res %= MOD;
	}
	return res;
}

// #define local
int main()
{
#ifdef local
	freopen("data.in", "r", stdin);
	freopen("ans.out", "w", stdout);
#endif	
	ll n, m;
	cin >> n >> m;
	ll ans = fp(2, m) - 1;
	ans = fp(ans, n);
	cout << ans << endl;
	return 0;
}