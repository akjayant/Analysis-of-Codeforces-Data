#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000;
const int mmod = 1e9 + 7;
long long a[maxn];
int main()
{
	int n, m;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	a[1] = 1; a[2] = 2;
	for(int i = 3; i <= max(n, m); i ++)
	{
		a[i] = a[i - 1] + a[i - 2];
		a[i] %= mmod;
	}
	cout << (2LL * (a[n] + a[m] - 1) + mmod)% mmod;
	return 0;
}