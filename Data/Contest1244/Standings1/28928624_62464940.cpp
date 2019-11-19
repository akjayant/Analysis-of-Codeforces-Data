#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; scanf( "%d", &t );
	for( int i = 1; i <= t; ++i ) {
		int a, b, c, d, k;
		scanf( "%d%d%d%d%d", &a, &b, &c, &d, &k );
		int T = ( a + c - 1 ) / c + ( b + d - 1 ) / d;
		if( T > k ) printf( "-1\n" ); else printf( "%d %d\n", ( a + c - 1 ) / c, ( b + d - 1 ) / d );
	}
	return 0;
}