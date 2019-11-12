#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9+7;
int n,m;

int p(int a,int b)
{
	if (b == 0)
		return 1;
	int tmp = p(a,b/2);
	if (b%2 == 0) return (tmp * tmp)%mod;
	return ((tmp * tmp)%mod * a)%mod;	
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int res = p(((p(2,m)-1)%mod + mod)%mod,n);
	cout << res;
}