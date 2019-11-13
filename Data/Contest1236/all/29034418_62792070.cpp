#include<bits/stdc++.h>
using namespace std;
const int maxn = 2005;
#define ll long long
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
ll n,m;
ll pow1(ll x, ll y)
{
	ll res = 1;
	while (y > 0)
	{
		if (y & 1)res = (res * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return res;
}
int main()
{
	while (cin >> n>>m)
	{
		cout << pow1(pow1(2, m) - 1, n) << endl;
	
	}
}