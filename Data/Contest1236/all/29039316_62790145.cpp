#include <bits/stdc++.h>
#define intt long long
#define pb push_back
#define endl '\n'
#define F first
#define S second
#define pii pair<int,int>
#define pil pair<int,intt>
#define pli pair<intt,int>
#define pll pair<intt,intt>
using namespace std;
const int mod = 1e9+7;
int i,j;
int powmod( int m, int k )
{
	if ( k == 0 )
	{
		return 1;
	}
	int res = powmod(m,k/2);
	if ( k&1 )
	{
		return 1LL*(1LL*res*res%mod)*m%mod;
	} 
	return (1LL*res*res)%mod;
}
int main()
{
	int n,m;
	cin >> n >> m;
	cout << powmod(1LL*(powmod(2,m)-1),n) << endl;
}