#include <bits/stdc++.h>
using namespace std ;
template < class R > inline void Readin( R &K ) {bool F=K=0;char C=getchar();while(C<'0'||C>'9')
{if(C=='-')F=1;C=getchar();}while(C<='9'&&C>='0')K=(K<<1)+(K<<3)+C-'0',C=getchar();if(F)K=-K;}
template < class R > inline bool Checkmax( R &A , R B ) { return A < B ? A = B , 1 : 0 ; }
template < class R > inline bool Checkmin( R &A , R B ) { return A > B ? A = B , 1 : 0 ; }
#define int long long
const int MaxN = 2000000 + 10 ;
int N , K , Ans ;
int Q[MaxN] , Top ;
bool Vis[MaxN] ;
signed main() {
	cin >> N >> K ;
	if( N * ( N + 1 ) / 2ll > K ) return not printf( "-1\n" ) ;
	K -= N * ( N + 1 ) / 2ll ;
	for(register int i = 0 ; ( ( ++i ) << 1 ) <= N + 1 ; ) {
		if( K <= ( N - i + 1 - i ) ) {
			assert( i + K <= N ) ;
			Vis[ Q[++Top] = i + K ] = 1 ;
			break ;
		}
		else {
			K -= ( N - i + 1 - i ) ;
			Vis[ Q[++Top] = N - i + 1 ] = 1 ;
		}
	}
	for(register int i = 0 ; ++i <= N ; )
		if( not Vis[i] )
			Q[++Top] = i ;
	int Ans = 0 ;
	for(register int i = 0 ; ++i <= N ; )
		Ans += max( i , Q[i] ) ;
	cout << Ans << endl ;
	for(register int i = 0 ; ++i <= N ; )
		printf( "%I64d " , i ) ;
	cout << endl ;
	for(register int i = 0 ; ++i <= N ; )
		printf( "%I64d " , Q[i] ) ;
	cout << endl ;
	return 0 ;
}