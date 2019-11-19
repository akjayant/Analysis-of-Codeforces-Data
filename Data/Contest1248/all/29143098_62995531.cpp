#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
int n, m;
LL ans = 0;
LL add ( LL x, LL y ) {
	return ((x+y)%MOD);
}
int main ()
{
	scanf("%d%d",&n,&m);
	if ( n == 1 ) {
		ans = 2;
	} else if ( n == 2 ) {
		ans = 4;
	} else if ( n == 3 ) {
		ans = 6;
	} else {
		LL pre = 2;
		LL prepre = 2;
		ans = 6;
		for( int i=3; i<n; ++i ) {
			ans = add(add(ans, pre), prepre);
			LL tmp = pre;
			pre = add(pre, prepre);
			prepre = tmp;
		}
	}
	//printf("%lld\n", ans);
	if ( m==1 ) {
		ans = add(ans, 0);
	} else if ( m == 2 ) {
		ans = add(ans, 2);
	} else if ( m == 3 ) {
		ans = add(ans, 4);
	} else {
		ans = add(ans, 4);		
		LL pre = 2;
		LL prepre = 2;
		for ( int i=3; i<m; ++i ) {
			ans = add(add(ans, pre), prepre);
			LL tmp = pre;
			pre = add(pre, prepre);
			prepre = tmp;
		}
	}
	printf("%lld\n", ans);
	return (0);
}