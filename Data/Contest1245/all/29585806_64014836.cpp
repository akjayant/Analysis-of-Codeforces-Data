#include <bits/stdc++.h>
using namespace std ;
template < class R > inline void Readin( R &K ) {bool F=K=0;char C=getchar();while(C<'0'||C>'9')
{if(C=='-')F=1;C=getchar();}while(C<='9'&&C>='0')K=(K<<1)+(K<<3)+C-'0',C=getchar();if(F)K=-K;}
template < class R > inline bool Checkmax( R &A , R B ) { return A < B ? A = B , 1 : 0 ; }
template < class R > inline bool Checkmin( R &A , R B ) { return A > B ? A = B , 1 : 0 ; }
int R , P , S , N ;
char Str[105] ;
char Ans[105] ;
int main() {
	int T ;
	Readin( T ) ;
	while( T-- ) {
		memset( Ans , 0 , sizeof Ans ) ;
		Readin( N ) ;
		Readin( R ) ;
		Readin( P ) ;
		Readin( S ) ;
		scanf( "%s" , Str + 1 ) ;
		for(register int i = 0 ; ++i <= N ; ) {
			if( Str[i] == 'R' ) {
				if( P ) {
					--P ;
					Ans[i] = 'P' ;
				}
				else Ans[i] = '0' ;
			}
			if( Str[i] == 'P' ) {
				if( S ) {
					--S ;
					Ans[i] = 'S' ;
				}
				else Ans[i] = '0' ;
			}
			if( Str[i] == 'S' ) {
				if( R ) {
					--R ;
					Ans[i] = 'R' ;
				}
				else Ans[i] = '0' ;
			}
		}
		int C = N ;
		for(register int i = 0 ; ++i <= N ; )
			if( Ans[i] ) {
				if( Ans[i] == '0' ) {
					--C ;
					if( P ) Ans[i] = 'P' , --P ;
					else if( R ) Ans[i] = 'R' , --R ;
					else Ans[i] = 'S' , --S ;
				}
			}
		if( C * 2 >= N ) {
			puts( "YES" ) ;
			puts( Ans + 1 ) ;
		}
		else puts( "NO" ) ;
	}
	return 0 ;
}