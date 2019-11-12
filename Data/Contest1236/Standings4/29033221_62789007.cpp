#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1e9 + 7;

ll p(ll x,ll y)
{
	if(y == 0)
		return 1;
	ll ans = 1;
	if(y&1)
		ans *= x;
	y = y/2;
	ll temp = p(x,y);
	temp = (temp*temp)%mod;
	return (temp*ans)%mod;
}


int main()
{
	ll n,m;
	cin >> n >> m;
	cout << p(p(2,m) -1,n) << endl;
}