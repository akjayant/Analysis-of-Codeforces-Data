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

int n, x;
int a[ 300 ][ 300 ];

int main() {
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) {
		if( i % 2 == 0 ) {
			for( int j = 0; j < n; ++j, ++x )
				a[ j ][ i ] = x;
		} else {
			for( int j = n - 1; j >= 0; --j, ++x )
				a[ j ][ i ] = x;
		}
	}
	for( int i = 0; i < n; ++i ) {
		for( int j = 0; j < n; ++j )
			printf( "%d ", a[ i ][ j ] + 1 );
		printf( "\n" );
	}
	return 0;
}