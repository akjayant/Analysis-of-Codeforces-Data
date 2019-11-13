#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#define PII pair<int,int>
#define VI vector<int>
#define VII vector<PII>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define _for0(i, _, n) for(int i=_;i<n;++i)
#define _for1(i, _, n) for(int i=_;i<=n;++i)
#define for0(i, n) for(int i=0;i<n;++i)
#define for1(i, n) for(int i=1;i<=n;++i)
#define rfor0(i, n) for(int i=n-1;i>=0;i--)
#define rfor1(i, n) for(int i=n;i>=1;i--)
#define all(it, obj) for(auto it=(obj).begin();it!=(obj).end();++it)
#define all_(_, it, obj) for(auto it=_;it!=(obj).end();++it)
#define rall(it, obj) for(auto it=(obj).rbegin();it!=(obj).rend();++it)
#define rall_(_, it, obj) for(auto it=_;it!=(obj).rend();++it)
using namespace std;
typedef long long LL;
#define N 100005
const LL MOD = 1e9+7;
LL mult ( LL x, LL y ) {
	return ((x*y)%MOD);
}
LL fast_pow ( LL x, LL y ) { // logY
	if ( y == 0 ) {
		return (1);
	} if ( y == 1 ) {
		return (x);
	}
	LL tmp = fast_pow(x, y>>1);
	if ( y&1 ) {
		return (mult(mult(tmp, tmp), x));
	} else {
		return (mult(tmp, tmp));
	}
}
LL n, m;
int main ()
{
	scanf("%lld%lld", &n, &m);
	LL ans = fast_pow(2, m);
	ans = (ans-1+MOD)%MOD;
	ans = fast_pow(ans, n);
	printf("%lld\n", ans);
	return (0);
}

