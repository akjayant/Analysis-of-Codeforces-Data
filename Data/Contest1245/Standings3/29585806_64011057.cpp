#include <bits/stdc++.h>
using namespace std ;
template < class R > inline void Readin( R &K ) {bool F=K=0;char C=getchar();while(C<'0'||C>'9')
{if(C=='-')F=1;C=getchar();}while(C<='9'&&C>='0')K=(K<<1)+(K<<3)+C-'0',C=getchar();if(F)K=-K;}
template < class R > inline bool Checkmax( R &A , R B ) { return A < B ? A = B , 1 : 0 ; }
template < class R > inline bool Checkmin( R &A , R B ) { return A > B ? A = B , 1 : 0 ; }
const int MaxN = 1e6 + 10 ;
const int Mod = 1e9 + 7 ;
char S[MaxN] ;
int N ;
int Dp[MaxN][3] ;
int main() {
	scanf( "%s" , S + 1 ) ;
	N = strlen( S + 1 ) ;
	Dp[0][0] = 1 ;
	for(register int i = 0 ; ++i <= N ; )
		switch( S[i] ) {
			case 'm' : {
				return not printf( "0\n" ) ;
			}
			case 'w' : {
				return not printf( "0\n" ) ;
			}
			case 'u' : {
				( Dp[i][1] += Dp[i-1][0] ) %= Mod ;
				( Dp[i][1] += Dp[i-1][1] ) %= Mod ;
				( Dp[i][1] += Dp[i-1][2] ) %= Mod ;
				( Dp[i][0] += Dp[i-1][1] ) %= Mod ;
				break ;
			}
			case 'n' : {
				( Dp[i][2] += Dp[i-1][0] ) %= Mod ;
				( Dp[i][2] += Dp[i-1][1] ) %= Mod ;
				( Dp[i][2] += Dp[i-1][2] ) %= Mod ;
				( Dp[i][0] += Dp[i-1][2] ) %= Mod ;
				break ;
			}
			default : {
				( Dp[i][0] += Dp[i-1][0] ) %= Mod ;
				( Dp[i][0] += Dp[i-1][1] ) %= Mod ;
				( Dp[i][0] += Dp[i-1][2] ) %= Mod ;
				break ;
			}
		}
	long long Ans = Dp[N][0] + Dp[N][1] + Dp[N][2] ;
	cout << Ans % Mod << endl ;
	return 0 ;
}