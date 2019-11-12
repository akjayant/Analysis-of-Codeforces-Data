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

int main() {
	int t;
	int a, b, c;
	int ans;
	scanf( "%d", &t );
	while( t-- ) {
		scanf( "%d%d%d", &a, &b, &c );
		ans = 0;
		for( int i = 0; i <= 100; ++i )
			for( int j = 0; j <= 100; ++j )
				if( i <= a && 2 * i + j <= b && 2 * j <= c )
					ans = max( ans, 3 * ( i + j ) );
		printf( "%d\n", ans );
	}
	return 0;
}