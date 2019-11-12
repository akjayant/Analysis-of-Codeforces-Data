#include<bits/stdc++.h>
using namespace std;
const int mmod = 1e9 + 7;
long long ksm(long long x, long long y)
{
	long long r;
	if(y == 0)return 1;
	if(y == 1)return x;
	if(y & 1)
	{
		r = ksm(x, y/2) % mmod;
		r = (r * r) % mmod;
		r = (r * x) % mmod;
		return r;
	}
	else
	{
		r = ksm(x, y/2) % mmod;
		r = (r * r) % mmod;
		return r;
	}
}
int n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	long long ans = ksm(2, m) - 1;
	ans = ksm(ans, n);
	ans %= mmod;
	cout << ans <<"\n";
	return 0;
}