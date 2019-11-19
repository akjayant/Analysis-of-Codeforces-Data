#include <bits/stdc++.h>
using namespace std ;
template < class R > inline void Readin( R &K ) {bool F=K=0;char C=getchar();while(C<'0'||C>'9')
{if(C=='-')F=1;C=getchar();}while(C<='9'&&C>='0')K=(K<<1)+(K<<3)+C-'0',C=getchar();if(F)K=-K;}
template < class R > inline bool Checkmax( R &A , R B ) { return A < B ? A = B , 1 : 0 ; }
template < class R > inline bool Checkmin( R &A , R B ) { return A > B ? A = B , 1 : 0 ; }
#define int long long
const int MaxN = 200000 + 10 ;
int N ;
int L[MaxN] , R[MaxN] ;
int Cost[3][MaxN] ;
int Dp[3][3][MaxN] ;
bool Vis[MaxN] ;
int Nods[MaxN] ;
int Col[MaxN] ;
signed main() {
	Readin( N ) ;
	for(register int i = 0 ; ++i <= N ; )
		Readin( Cost[0][i] ) ;
	for(register int i = 0 ; ++i <= N ; )
		Readin( Cost[1][i] ) ;
	for(register int i = 0 ; ++i <= N ; )
		Readin( Cost[2][i] ) ;
	for(register int i = 0 ; ++i < N ; ) {
		register int U , V ;
		Readin( U ) ;
		Readin( V ) ;
		if( R[U] or R[V] ) return not printf( "-1\n" ) ;
		if( L[U] ) R[U] = V ; else L[U] = V ;
		if( L[V] ) R[V] = U ; else L[V] = U ;
	}
	int Nod ;
	for(register int i = 0 ; ++i <= N ; ) {
		assert( i != N ) ;
		if( R[i] == 0 ) {
			Nod = i ;
			break ;
		}
	}
	memset( Dp , 127 , sizeof Dp ) ;
	for(register int a = 0 ; a < 3 ; ++a )
		for(register int b = 0 ; b < 3 ; ++b )
			if( a != b )
				Dp[a][b][2] = Cost[a][Nod] + Cost[b][L[Nod]] ;
	for(register int i = 0 ; ++i <= N ; ) {
		Vis[Nod] = true ;
		if( i >= 3 ) {
			for(register int a = 0 ; a < 3 ; ++a )
				for(register int b = 0 ; b < 3 ; ++b )
					for(register int c = 0 ; c < 3 ; ++c )
						if( a != b and b != c and a != c )
							Checkmin( Dp[b][c][i] , Dp[a][b][i-1] + Cost[c][Nod] ) ;
		}
		Nods[i] = Nod ;
		Nod = Vis[L[Nod]] ? R[Nod] : L[Nod] ;
	}
	int Ans = 1ll << 60 , A , B ;
	for(register int a = 0 ; a < 3 ; ++a )
		for(register int b = 0 ; b < 3 ; ++b )
			if( a != b )
				if( Checkmin( Ans , Dp[a][b][N] ) ) {
					A = a ;
					B = b ;
				}
	cout << Ans << endl ;
	Col[Nods[N]] = B ;
	Col[Nods[N-1]] = A ;
	for(register int i = N - 2 ; i ; --i ) {
		Col[Nods[i]] = 3 - A - B ;
		B = A ;
		A = Col[Nods[i]] ;
	}
	for(register int i = 0 ; ++i <= N ; )
		printf( "%d " , Col[i] + 1 ) ;
	cout << endl ;
	return 0 ;
}