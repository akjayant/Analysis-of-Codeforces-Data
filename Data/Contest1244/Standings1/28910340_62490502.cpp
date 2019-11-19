#include <bits/stdc++.h>
using namespace std ;
template < class R > inline void Readin( R &K ) {bool F=K=0;char C=getchar();while(C<'0'||C>'9')
{if(C=='-')F=1;C=getchar();}while(C<='9'&&C>='0')K=(K<<1)+(K<<3)+C-'0',C=getchar();if(F)K=-K;}
template < class R > inline bool Checkmax( R &A , R B ) { return A < B ? A = B , 1 : 0 ; }
template < class R > inline bool Checkmin( R &A , R B ) { return A > B ? A = B , 1 : 0 ; }
#define int long long
const int MaxN = 200000 + 10 ;
int N , K , A[MaxN] ;
int L , R ;
signed main() {
	Readin( N ) ;
	Readin( K ) ;
	for(register int i = 0 ; ++i <= N ; )
		Readin( A[i] ) ;
	sort( A + 1 , A + 1 + N ) ;
	L = 1 , R = N ;
	while( L < R ) {
		if( L <= ( N - R + 1 ) ) {
			if( L * ( A[L+1] - A[L] ) >= K )
				return not printf( "%I64d\n" , A[R] - A[L] - K / L ) ;
			K -= L * ( A[L+1] - A[L] ) ;
			++L ;
		}
		else {
			if( ( N - R + 1 ) * ( A[R] - A[R-1] ) >= K )
				return not printf( "%I64d\n" , A[R] - A[L] - K / ( N - R + 1 ) ) ;
			K -= ( N - R + 1 ) * ( A[R] - A[R-1] ) ;
			--R ;
		}
	}
	return not printf( "0\n" ) ;
}