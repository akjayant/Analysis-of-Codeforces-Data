#include <bits/stdc++.h>
using namespace std ;
template < class R > inline void Readin( R &K ) {bool F=K=0;char C=getchar();while(C<'0'||C>'9')
{if(C=='-')F=1;C=getchar();}while(C<='9'&&C>='0')K=(K<<1)+(K<<3)+C-'0',C=getchar();if(F)K=-K;}
template < class R > inline bool Checkmax( R &A , R B ) { return A < B ? A = B , 1 : 0 ; }
template < class R > inline bool Checkmin( R &A , R B ) { return A > B ? A = B , 1 : 0 ; }
#define int long long
const int MaxN = 2000 + 10 ;
int N ;
char S[MaxN] ;
signed main() {
	int T ;
	Readin( T ) ;
	while( T-- ) {
		int Ans = 10000000 ;
		Readin( N ) ;
		scanf( "%s" , S + 1 ) ;
		for(register int i = 0 ; ++i <= N ; )
			if( S[i] == '1' )
				Checkmin( Ans , min( i - 1 , N - i ) ) ;
		cout << max( N - Ans << 1 , N ) << endl ;
	}
	return 0 ;
}