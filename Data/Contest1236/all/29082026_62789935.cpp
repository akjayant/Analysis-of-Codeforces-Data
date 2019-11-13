#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MAX_INF 0x7f
#define MAX_INF_VAL 0x7f7f7f7f
#define pi 3.141592653589
#define eps 1e-10
//#define p 2173412051LL
#define sz 2
 
using namespace std;

ll pow_mod( ll, ll, ll );

int main() {
	ll n, m, p = 1000000007;
	ll x;
	scanf( "%lld%lld", &n, &m );
	x = pow_mod( 2, m, p );
	--x;
	if( x < 0 )
		x += p;
	printf( "%lld", pow_mod( x, n, p ) );
	return 0;
}

ll pow_mod( ll x, ll y, ll p ) {
	ll res = 1;
	while( y ) {
		if( y & 1 ) {
			res *= x;
			res %= p;
		}
		x *= x;
		x %= p;
		y >>= 1;
	}
	return res;
}