#include <bits/stdc++.h>
using namespace std ;
template < class R > inline void Readin( R &K ) {bool F=K=0;char C=getchar();while(C<'0'||C>'9')
{if(C=='-')F=1;C=getchar();}while(C<='9'&&C>='0')K=(K<<1)+(K<<3)+C-'0',C=getchar();if(F)K=-K;}
template < class R > inline bool Checkmax( R &A , R B ) { return A < B ? A = B , 1 : 0 ; }
template < class R > inline bool Checkmin( R &A , R B ) { return A > B ? A = B , 1 : 0 ; }
int main() {
	int T , A , B ;
	Readin( T ) ;
	while( T-- ) {
		Readin( A ) ;
		Readin( B ) ;
		printf( "%s\n" , __gcd( A , B ) == 1 ? "Finite" : "Infinite" ) ;
	}
	return 0 ;
}