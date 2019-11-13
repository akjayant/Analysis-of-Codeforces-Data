#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int mod = 1e9+7;

int powll(int b, int p)
{
	if(!p)return 1;
	if(p==1)return b%mod;
	int ret = powll(b, p/2);
	ret = (ret * ret) % mod;
	if(p&1)ret = (ret * (b%mod))%mod;
	return ret;
}


#undef int
int main()
{
#define int long long int
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin>>n>>m;
	cout<<powll(((powll(2, m) + mod - 1) % mod), n);

	return 0;
}