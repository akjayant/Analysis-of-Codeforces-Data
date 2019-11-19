#include <bits/stdc++.h>
using namespace std ;
template < class R > inline void Readin( R &K ) {bool F=K=0;char C=getchar();while(C<'0'||C>'9')
{if(C=='-')F=1;C=getchar();}while(C<='9'&&C>='0')K=(K<<1)+(K<<3)+C-'0',C=getchar();if(F)K=-K;}
template < class R > inline bool Checkmax( R &A , R B ) { return A < B ? A = B , 1 : 0 ; }
template < class R > inline bool Checkmin( R &A , R B ) { return A > B ? A = B , 1 : 0 ; }
const int MaxN = 2000 + 10 ;
const int MaxM = 4000000 + 10 ;
int N , M ;
int X[MaxN] , Y[MaxN] , C[MaxN] , K[MaxN] ;
struct Edge {
	int U , V ;
	long long W ;
} ;
Edge E[MaxM] ;
int Find[MaxN] , Min[MaxN] ;
int F( int N ) {
	return N == Find[N] ? N : Find[N] = F( Find[N] ) ;
}
int Opt[MaxM][2] , Opts ;
int Ans[MaxN] , Nods ;
int main() {
	Readin( N ) ;
	for(register int i = 0 ; ++i <= N ; )
		Readin( X[i] ) , Readin( Y[i] ) ;
	for(register int i = 0 ; ++i <= N ; )
		Readin( C[i] ) ;
	for(register int i = 0 ; ++i <= N ; )
		Readin( K[i] ) ;
	for(register int i = 0 ; ++i <= N ; )
		for(register int j = i ; ++j <= N ; ) {
			++M ;
			E[M].U = i ;
			E[M].V = j ;
			E[M].W = 1ll * ( abs( X[i] - X[j] ) + abs( Y[i] - Y[j] ) ) * ( K[i] + K[j] ) ;
		}
	sort( E + 1 , E + 1 + M , []( Edge A , Edge B ) {
		return A.W < B.W ;
	} ) ;
	for(register int i = 0 ; ++i <= N ; )
		Find[i] = Min[i] = i ;
	register long long Minans = 0 ;
	for(register int i = 0 ; ++i <= M ; ) {
		register int U = E[i].U , V = E[i].V ;
		U = F(U) ;
		V = F(V) ;
		if( U == V ) continue ;
		if( E[i].W >= max( C[Min[U]] , C[Min[V]] ) ) continue ;
		Minans += E[i].W ;
		++Opts ;
		Opt[Opts][0] = E[i].U ;
		Opt[Opts][1] = E[i].V ;
		Find[U] = V ;
		if( C[Min[V]] > C[Min[U]] ) Min[V] = Min[U] ;
	}
	for(register int i = 0 ; ++i <= N ; ) 
		if( Find[i] == i ) {
			Ans[++Nods] = Min[i] ;
			Minans += C[Min[i]] ;
		}
	assert( Nods + Opts == N ) ;
	printf( "%I64d\n" , Minans ) ;
	printf( "%d\n" , Nods ) ;
	for(register int i = 0 ; ++i <= Nods ; )
		printf( "%d " , Ans[i] ) ;
	printf( "\n%d\n" , Opts ) ;
	for(register int i = 0 ; ++i <= Opts ; )
		printf( "%d %d\n" , Opt[i][0] , Opt[i][1] ) ;
	return 0 ;
}