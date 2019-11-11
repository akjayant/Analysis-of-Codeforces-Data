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

int gcd( int, int );
 
int main() {
	int t;
	int x, y;
	scanf( "%d", &t );
	while( t-- ) { 
		scanf( "%d%d", &x, &y );
		if( gcd( x, y ) == 1 )
			printf( "Finite\n" );
		else
			printf( "Infinite\n" );
	}
	return 0;
}

int gcd( int a, int b ) {
	return b? gcd( b, a % b ) : a;
}