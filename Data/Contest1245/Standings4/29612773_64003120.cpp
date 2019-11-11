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

int t;
int num[ 26 ];
char s[ 110 ];
char ans[ 110 ];

int main() {
	int t;
	int n;
	int x, y, z;
	int tot;
	scanf( "%d", &t );
	while( t-- ) {
		scanf( "%d", &n );
		scanf( "%d%d%d", &x, &y, &z );
		scanf( "%s", s );
		memset( num, 0, sizeof( num ) );
		memset( ans, 0, sizeof( ans ) );
		tot = 0;
		for( int i = 0; i < n; ++i )
			++num[ s[ i ] - 'A' ];
		tot += min( x, num[ 'S' - 'A' ] );
		tot += min( y, num[ 'R' - 'A' ] );
		tot += min( z, num[ 'P' - 'A' ] );
		if( tot * 2 >= n ) {
			printf( "YES\n" );
			for( int i = 0; i < n; ++i ) {
				if( s[ i ] == 'R' ) {
					if( y ) {
						ans[ i ] = 'P';
						--y;
					}
				} else if( s[ i ] == 'P' ) {
					if( z ) {
						ans[ i ] = 'S';
						--z;
					}
				} else {
					if( x ) {
						ans[ i ] = 'R';
						--x;
					}
				}
			}
			for( int i = 0; i < n; ++i )
				if( ans[ i ] == 0 ) {
					if( x ) {
						ans[ i ] = 'R';
						--x;
					} else if( y ) {
						ans[ i ] = 'P';
						--y;
					} else if( z ) {
						ans[ i ] = 'S';
						--z;
					}
				}
			printf( "%s\n", ans );
		} else {
			printf( "NO\n" );
		}
	}
	return 0;
}