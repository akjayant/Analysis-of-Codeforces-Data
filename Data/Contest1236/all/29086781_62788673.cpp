#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

LL n , m;
 
LL qp(LL x , LL y)
{
	LL ret = 1 , p = x;
	while (y)
	{
		if (y%2) ret = ret*p%mod;
		y /= 2;
		p = p*p%mod;
	}
	return ret;
}

int main()
{
	int i , j;
	cin >> n >> m;
	cout << qp((qp(2,m)+mod-1)%mod,n) << "\n";
	return 0;
}
