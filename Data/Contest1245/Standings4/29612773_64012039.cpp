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

char s[ 100010 ];
ll p = 1000000007;
ll fk[ 100010 ];
ll st[ 100010 ];

void pre();

int main() {
	int n, m = 0;
	ll ans = 1;
	pre();
	scanf( "%s", s );
	n = strlen( s );
	if( s[ 0 ] == 'w' || s[ 0 ] == 'm' ) {
		printf( "0" );
		return 0;
	}
	if( s[ 0 ] == 'u' || s[ 0 ] == 'n' )
		st[ ++m ] = 1;
	for( int i = 1; i < n; ++i ) {
		if( s[ i ] == 'w' || s[ i ] == 'm' ) {
			printf( "0" );
			return 0;
		}
		if( s[ i ] == 'u' || s[ i ] == 'n' ) {
			if( s[ i ] == s[ i - 1 ] )
				++st[ m ];
			else
				st[ ++m ] = 1;
		}
	}
	for( int i = 1; i <= m; ++i ) {
		ans *= fk[ st[ i ] ];
		ans %= p;
	}
	printf( "%lld", ans );
	return 0;
}

void pre() {
	fk[ 1 ] = 1;
	fk[ 2 ] = 2;
	for( int i = 3; i <= 100000; ++i ) {
		fk[ i ] = fk[ i - 2 ] + fk[ i - 1 ];
		fk[ i ] %= p;
	}
}