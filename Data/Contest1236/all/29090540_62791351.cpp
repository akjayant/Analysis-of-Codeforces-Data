#include <bits/stdc++.h>
#define fs first
#define sc second
#define mx 105
#define mod 1000000007
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define all(a) a.begin(),a.end()
using namespace std;
ll bigmod(ll a, ll p){
	a %= mod;
	ll ret = 1;
	while(p){
		if(p&1) ret = ret * a % mod;
		a = a * a % mod;
		p /= 2;
	}
	return ret;
}
int main()
{
	// memset(dp, -1, sizeof dp);
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%lld\n", bigmod(bigmod(2, m)+1ll*mod-1ll, n));
	return 0;
}